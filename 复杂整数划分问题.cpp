///���������������� (POJ 4119)
/*
����
��������n ��ʾ��һϵ��������֮�ͣ�n=n1+n2+��+nk, ����n1>=n2>=��>=nk>=1 ��k>=1 ��
������n �����ֱ�ʾ��Ϊ������n �Ļ��֡�

����
��׼���������������������ݡ�ÿ�����������һ����������,������������N �� K��
(0 < N <= 50, 0 < K <= N)
���
����ÿ��������ݣ����������������:
��һ��: N���ֳ�K��������֮�͵Ļ�����Ŀ
�ڶ���: N���ֳ����ɸ���ͬ������֮�͵Ļ�����Ŀ
������: N���ֳ����ɸ���������֮�͵Ļ�����Ŀ
��������
5 2
�������
2
3
3
��ʾ
��һ��: 4+1, 3+2,
�ڶ���: 5��4+1��3+2
������: 5��1+1+3�� 1+1+1+1+1+1
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
    //�ⲻ���Ƿ�ƻ�������𣬾�Ȼ��ʼ����ά�������~~

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
