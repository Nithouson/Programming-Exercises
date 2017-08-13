///复杂整数划分问题 (POJ 4119)
/*
描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。

输入
标准的输入包含若干组测试数据。每组测试数据是一行输入数据,包括两个整数N 和 K。
(0 < N <= 50, 0 < K <= N)
输出
对于每组测试数据，输出以下三行数据:
第一行: N划分成K个正整数之和的划分数目
第二行: N划分成若干个不同正整数之和的划分数目
第三行: N划分成若干个奇正整数之和的划分数目
样例输入
5 2
样例输出
2
3
3
提示
第一行: 4+1, 3+2,
第二行: 5，4+1，3+2
第三行: 5，1+1+3， 1+1+1+1+1+1
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int divnum[51][51];
    for(int m=1;m<=50;m++)
    {
        for(int k=1;k<=50;k++)
        {
            if(k>m) divnum[m][k]=0;
            else if(k==m) divnum[m][k]=1;
            else
            {
                divnum[m][k]=divnum[m-k][k]+divnum[m-1][k-1];
            }
        }
    }
    //这不就是分苹果问题吗，居然开始用三维数组回溯~~

    int divdiff[51];
    int dp[51][51];
    dp[0][0]=1;
    divdiff[0]=1;
    for(int m=1;m<=50;m++)
    {
        dp[m][0]=0;
        for(int lim=1;lim<=m;lim++)
        {
             int res=0;
             for(int p=lim;p>=1;p--)
             {
                 res+=dp[m-p][p-1>m-p?m-p:p-1];
             }
             dp[m][lim]=res;
        }
        divdiff[m]=dp[m][m];
    }

    int divodd[51];
    int ddp[51][51];
    ddp[0][0]=1;
    for(int m=1;m<=50;m++)
    {
        ddp[m][0]=0;
        for(int lim=1;lim<=m;lim+=1)
        {
             int res=0;
             for(int p=lim;p>=1;p-=2)
             {
                 int nlim=p>m-p?m-p:p;
                 if(nlim%2==0&&nlim!=0) nlim-=1;
                 res+=ddp[m-p][nlim];
             }
             ddp[m][lim]=res;
        }
        divodd[m]=m%2==1?ddp[m][m]:ddp[m][m-1];
    }
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        printf("%d\n",divnum[n][k]);
        printf("%d\n",divdiff[n]);
        printf("%d\n",divodd[n]);
    }
    return 0;
}
