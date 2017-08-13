///Charm Bracelet (POJ4131)
/*
描述
Bessie has gone to the mall's jewelry store and spies a charm bracelet.
Of course, she'd like to fill it with the best charms possible from the N(1 ≤ N≤ 3,402) available charms.
Each charm iin the supplied list has a weight Wi(1 ≤ Wi≤ 400), a 'desirability' factor Di(1 ≤ Di≤ 100),
and can be used at most once.
Bessie can only support a charm bracelet whose weight is no more than M(1 ≤ M≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating,
deduce the maximum possible sum of ratings.

输入
Line 1: Two space-separated integers: N and M
Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di
输出
Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved
given the weight constraints
样例输入
4 6
1 4
2 6
3 12
2 7
样例输出
23
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    short weight[N+1],desire[N+1];
    for(int i=1;i<=N;i++)
    {
        cin>>weight[i]>>desire[i];
    }
    int dp[N+1][M+1];
    for(int limit=0;limit<=M;limit++)
    {
        dp[0][limit]=0;
    }
    for(int item=1;item<=N;item++)
    {
        for(int limit=0;limit<=M;limit++)
        {
            if(limit<weight[item]) dp[item][limit]=dp[item-1][limit];
            else
            {
                int gainA=dp[item-1][limit];
                int gainB=dp[item-1][limit-weight[item]]+desire[item];
                dp[item][limit]=gainA>gainB?gainA:gainB;
                //cout<<item<<" "<<limit<<" "<<dp[item][limit]<<endl;
            }
        }
    }
    cout<<dp[N][M];
    return 0;
}
