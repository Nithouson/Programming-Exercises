///���̷ָ�(POJ 1191)
/*
����
��һ����*�������̽������·ָ��ԭ���̸���һ��������̲�ʹʣ�²���Ҳ�Ǿ��Σ��ٽ�ʣ�µĲ��ּ�����˷ָ��������(n-1)�κ�
��ͬ���ʣ�µľ������̹���n��������̡�(ÿ���иֻ���������̸��ӵı߽���)
ԭ������ÿһ����һ����ֵ��һ��������̵��ܷ�Ϊ�����������ֵ֮�͡�
������Ҫ�����̰���������ָ��n��������̣���ʹ�����������ֵܷľ�������С��
���̶Ը��������̼�n��������������Сֵ��
����
��1��Ϊһ������n(1 < n < 15)��
��2������9��ÿ��Ϊ8��С��100�ķǸ���������ʾ��������Ӧ���ӵķ�ֵ��ÿ����������֮����һ���ո�ָ���
���
��һ������Ϊ������������뾫ȷ��С�������λ����
��������
3
1 1 1 1 1 1 1 3
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 1 1 1 1 0 3
�������
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
        }//�ر�ע��ֻ����һ�����У������ִ��ֳ�ʱ��
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
