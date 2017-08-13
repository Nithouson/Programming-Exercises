///神奇的口袋 (POJ 2755)
/*
描述
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。
John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。
John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。
现在的问题是，John有多少种不同的选择物品的方式。
输入
输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。
接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。
输出
输出不同的选择物品的方式的数目。
样例输入
3
20
20
20
样例输出
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
