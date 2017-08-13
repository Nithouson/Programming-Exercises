///最大上升子序列和 (OJ 3532)
/*
描述
一个数的序列bi，当b1 < b2 < ... < bS的时候，我们称这个序列是上升的。
对于给定的一个序列(a1, a2, ...,aN)，我们可以得到一些上升的子序列(ai1, ai2, ..., aiK)，
这里1 <= i1 < i2 < ... < iK <= N。比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，
如(1, 7), (3, 4, 8)等等。
这些子序列中序列和最大为18，为子序列(1, 3, 5, 9)的和.
你的任务，就是对于给定的序列，求出最大上升子序列和。
注意，最长的上升子序列的和不一定是最大的，比如序列(100, 1, 2, 3)的最大上升子序列和为100，
而最长上升子序列为(1, 2, 3)
输入
输入的第一行是序列的长度N (1 <= N <= 1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000（可能重复）。
输出
最大上升子序列和
样例输入
7
1 7 3 5 9 4 8
样例输出
18
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int k,i,j;
    int num[1000];
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>num[i];
    }
    int dp[k],maxs=num[0];
    dp[0]=num[0];
    for(i=1;i<k;i++)
    {
        dp[i]=num[i];
        for(j=0;j<i;j++)
        {
            if(num[j]<num[i]&&dp[j]+num[i]>dp[i])
            {
                dp[i]=dp[j]+num[i];
            }
        }
        //cout<<i<<" "<<dp[i]<<endl;
        if(dp[i]>maxs) maxs=dp[i];
    }
    cout<<maxs<<endl;
    return 0;
}
