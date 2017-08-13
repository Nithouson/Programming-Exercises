///最大子矩阵 (POJ 2766)
/*
已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。

比如，如下4 * 4的矩阵

0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

的最大子矩阵是

9 2
-4 1
-1 8

这个子矩阵的大小是15。
输入
输入是一个N * N的矩阵。输入的第一行给出N (0 < N <= 100)。再后面的若干行中，依次（首先从左到右给出第一行的N个整数，再从左到右给出第二行的N个整数……）给出矩阵中的N2个整数，整数之间由空白字符分隔（空格或者空行）。已知矩阵中整数的范围都在[-127, 127]。
输出
输出最大子矩阵的大小。
样例输入
4
0 -2 -7 0 9 2 -6 2
-4 1 -4  1 -1

8  0 -2
样例输出
15
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N,i,j;
    cin>>N;
    short grid[N][N];
    int sum[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>grid[i][j];
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i==0)
            {
                if(j==0) sum[i][j]=grid[i][j];
                else sum[i][j]=sum[i][j-1]+grid[i][j];
            }
            else
            {
                if(j==0) sum[i][j]=sum[i-1][j]+grid[i][j];
                else sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+grid[i][j];
            }
        }
    }
    int maxsum=-128,cur,ai,aj,bi,bj;
    for(ai=0;ai<N;ai++)
    {
        for(aj=0;aj<N;aj++)
        {
            for(bi=ai;bi<N;bi++)
            {
                for(bj=aj;bj<N;bj++)
                {
                    if(ai==0&&aj==0) cur=sum[bi][bj];
                    else if(ai==0) cur=sum[bi][bj]-sum[bi][aj-1];
                    else if(aj==0) cur=sum[bi][bj]-sum[ai-1][bj];
                    else cur=sum[bi][bj]-sum[ai-1][bj]-sum[bi][aj-1]+sum[ai-1][aj-1];
                    if(cur>maxsum) maxsum=cur;
                }
            }
        }
    }
    cout<<maxsum<<endl;
    return 0;
}
