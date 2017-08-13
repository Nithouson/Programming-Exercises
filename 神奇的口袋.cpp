///����Ŀڴ� (POJ 2755)
/*
����
��һ������Ŀڴ����ܵ��ݻ���40��������ڴ����Ա��һЩ��Ʒ����Щ��Ʒ�������������40��
John������n����Ҫ�õ�����Ʒ��ÿ����Ʒ������ֱ���a1��a2����an��
John���Դ���Щ��Ʒ��ѡ��һЩ�����ѡ����������������40����ô�����������Ŀڴ���John�Ϳ��Եõ���Щ��Ʒ��
���ڵ������ǣ�John�ж����ֲ�ͬ��ѡ����Ʒ�ķ�ʽ��
����
����ĵ�һ����������n (1 <= n <= 20)����ʾ��ͬ����Ʒ����Ŀ��
��������n�У�ÿ����һ��1��40֮������������ֱ����a1��a2����an��ֵ��
���
�����ͬ��ѡ����Ʒ�ķ�ʽ����Ŀ��
��������
3
20
20
20
�������
3
*/


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n,i,w[20];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>w[i];
    }
    int dp[21][41];
    memset(dp,0,sizeof(dp));
    dp[1][w[0]]=1;
    for(int item=2;item<=n;item++)
    {
        for(int curw=1;curw<=40;curw++)
        {
            if(curw<w[item-1]) dp[item][curw]=dp[item-1][curw];
            else if(curw==w[item-1]) dp[item][curw]=dp[item-1][curw]+1;
            else
            {
                dp[item][curw]=dp[item-1][curw]+dp[item-1][curw-w[item-1]];
            }
        }
    }
    cout<<dp[n][40]<<endl;
    return 0;
}
