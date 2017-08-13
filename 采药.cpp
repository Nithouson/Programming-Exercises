///采药 (POJ 2726&2773)
/*
描述
辰辰是个很有潜能、天资聪颖的孩子，他的梦想是称为世界上最伟大的医师。
为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。
医师把他带到个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，
采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，
你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”
如果你是辰辰，你能完成这个任务吗？
输入
输入的第一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），T代表总共能够用来采药的时间，M代表山洞里的草药的数目。接下来的M行每行包括两个在1到100之间（包括1和100）的的整数，分别表示采摘某株草药的时间和这株草药的价值。
输出
输出只包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。
样例输入
70 3
71 100
69 1
1 2
样例输出
3
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int T,M,i,t;
    int time[101],value[101];
    cin>>T>>M;
    for(i=1;i<=M;i++)
    {
        cin>>time[i]>>value[i];
    }
    int dp[T+1][M+1];
    for(t=0;t<=T;t++)
    {
        dp[t][0]=0;
    }
    for(i=1;i<=M;i++)
    {
        for(t=0;t<=T;t++)
        {
            if(t<time[i]) dp[t][i]=dp[t][i-1];
            else
            {
                int m=dp[t][i-1],n=dp[t-time[i]][i-1]+value[i];
                dp[t][i]=m>n?m:n;
            }
        }
    }
    cout<<dp[T][M];
    return 0;
}
