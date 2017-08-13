///棋盘分割(POJ 1191)
/*
描述
将一个８*８的棋盘进行如下分割：将原棋盘割下一块矩形棋盘并使剩下部分也是矩形，再将剩下的部分继续如此分割，这样割了(n-1)次后，
连同最后剩下的矩形棋盘共有n块矩形棋盘。(每次切割都只能沿着棋盘格子的边进行)
原棋盘上每一格有一个分值，一块矩形棋盘的总分为其所含各格分值之和。
现在需要把棋盘按上述规则分割成n块矩形棋盘，并使各矩形棋盘总分的均方差最小。
请编程对给出的棋盘及n，求出均方差的最小值。
输入
第1行为一个整数n(1 < n < 15)。
第2行至第9行每行为8个小于100的非负整数，表示棋盘上相应格子的分值。每行相邻两数之间用一个空格分隔。
输出
仅一个数，为均方差（四舍五入精确到小数点后三位）。
样例输入
3
1 1 1 1 1 1 1 3
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 1 1 1 1 0 3
样例输出
1.633
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
int board[8][8];
int sum[8][8];
int cache[8][8][8][8][14];

int Partsum(int x1,int y1,int x2,int y2)
{
    int res=sum[x2][y2];
    if(x1!=0) res-=sum[x1-1][y2];
    if(y1!=0) res-=sum[x2][y1-1];
    if(x1!=0&&y1!=0) res+=sum[x1-1][y1-1];
    return res;
}

int Divide(int x1,int y1,int x2,int y2,int n)
{
    if(cache[x1][y1][x2][y2][n]>=0) return cache[x1][y1][x2][y2][n];
    if(n==1) return Partsum(x1,y1,x2,y2)*Partsum(x1,y1,x2,y2);
    else
    {
        int xdiv,ydiv,curmin=1<<30,temp;
        for(xdiv=x1+1;xdiv<=x2;xdiv++)
        {
            temp=Divide(x1,y1,xdiv-1,y2,1)+Divide(xdiv,y1,x2,y2,n-1);
            curmin=curmin>temp?temp:curmin;
            temp=Divide(x1,y1,xdiv-1,y2,n-1)+Divide(xdiv,y1,x2,y2,1);
            curmin=curmin>temp?temp:curmin;
        }//特别注意只能在一块里切！否则又错又超时。
        for(ydiv=y1+1;ydiv<=y2;ydiv++)
        {
            temp=Divide(x1,y1,x2,ydiv-1,1)+Divide(x1,ydiv,x2,y2,n-1);
            curmin=curmin>temp?temp:curmin;
            temp=Divide(x1,y1,x2,ydiv-1,n-1)+Divide(x1,ydiv,x2,y2,1);
            curmin=curmin>temp?temp:curmin;
        }
        cache[x1][y1][x2][y2][n]=curmin;
        return curmin;
    }
}

int main()
{
    int n,i,j,minsq,total=0;
    memset(sum,-1,sizeof(sum));
    memset(cache,-1,sizeof(cache));
    cin>>n;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            cin>>board[i][j];
            total+=board[i][j];
        }
    }
    for(i=0;i<8;i++)
    {
        int rsum=0;
        for(j=0;j<8;j++)
        {
            rsum+=board[i][j];
            sum[i][j]=rsum;
        }
    }
    for(i=1;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            sum[i][j]+=sum[i-1][j];
        }
    }
    minsq=Divide(0,0,7,7,n);
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(1.0*(minsq-1.0*total*total/n)/n)<<endl;
    return 0;
}
