///���͹� (POJ 4118)
/*
����
������ϢѧԺ��ͬѧС����ҵ֮����㴴ҵ���͹�.���ڹ���n ���ص�ɹ�ѡ��
С���������ѡ����ʵ�λ�ÿ���һЩ�͹ݡ��� n ���ص�������ͬһ��ֱ���ϡ�
������һ����������m1, m2, ... mn ����ʾ���ǵ����λ�á����ڵضι�ϵ,���͹ݵ������������ͬ��
������pi ��ʾ��mi �����͹ݵ�����Ϊ�˱����Լ��Ĳ͹ݵ��ڲ�����,�͹�֮��ľ���������k��
�������С��ѡ��һ�����������ķ�����

����
��׼���������������������ݡ������һ��������T (1 <= T <= 1000) ��������T��������ݡ�
��������T�������Ĳ��ԡ�ÿ�����������3��,
��1��:�ص����� n (n < 100), �������� k (k > 0 && k < 1000).
��2��:n ���ص��λ��m1 , m2, ... mn ( 1000000 > mi > 0 ��Ϊ����,��������)
��3��:n ���ص�Ĳ͹�����p1 , p2, ... pn ( 1000 > pi > 0 ��Ϊ����)
���
����ÿ��������ݿ��ܵ��������
��������
2
3 11
1 2 15
10 2 30
3 16
1 2 15
10 2 30
�������
40
30
*/

#include <iostream>
#define MAX 100
using namespace std;

int main()
{
    int T,n,k,i;
    int pos[MAX],profit[MAX],dp[MAX],maxgain;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        k=k+1;
        for(i=0;i<n;i++)
        {
            cin>>pos[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>profit[i];
        }
        for(i=0;i<n;i++)
        {
            if(i==0||pos[i]<=k) dp[i]=profit[i];
            else
            {
                dp[i]=0;
                int oprev,p;
                for(oprev=i-1;oprev>=0&&pos[i]-pos[oprev]<k;oprev--)
                if(oprev==-1) {dp[i]=profit[i];continue;}
                for(p=oprev;p>=0&&pos[oprev]-pos[p]<k;p--)
                {
                    dp[i]=dp[p]>dp[i]?dp[p]:dp[i];
                }
                dp[i]+=profit[i];
            }
        }
        maxgain=0;
        for(i=0;i<n;i++)
        {
            maxgain=dp[i]>maxgain?dp[i]:maxgain;
        }
        cout<<maxgain<<endl;
    }
    return 0;
}
