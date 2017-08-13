///炮兵阵地 (POJ 1185)
/*
描述
司令部的将军们打算在N*M的网格地图上部署他们的炮兵部队。
一个N*M的地图由N行M列组成，地图的每一格可能是山地（用"H" 表示），也可能是平原（用"P"表示），如下图。
在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；
一支炮兵部队在地图上的攻击范围如图中黑色区域所示：
如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：
沿横向左右各两格，沿纵向上下各两格。图上其它白色网格均攻击不到。
从图上可见炮兵的攻击范围不受地形的影响。
现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，
即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。
输入
第一行包含两个由空格分割开的正整数，分别表示N和M；
接下来的N行，每一行含有连续的M个字符('P'或者'H')，中间没有空格。按顺序表示地图中每一行的数据。N <= 100；M <= 10。
输出
仅一行，包含一个整数K，表示最多能摆放的炮兵部队的数量。
样例输入
5 4
PHPP
PPHH
PPPP
PHPP
PHHP
样例输出
6
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;///n rows,m columns
int atlas[100];
int num=0,curstate[10];
int maxcannon;
int dp[100][100][100];

struct row
{
    int state,cannon;
}rowstate[100];

void CalStates(int pos)
{
    if(pos==m)
    {
        int cannonnum=0;
        for(int c=0;c<m;c++)
        {
            rowstate[num].state+=curstate[c];
            cannonnum+=curstate[c];
            if(c!=m-1) rowstate[num].state<<=1;
        }
        rowstate[num].cannon=cannonnum;
        num++;
        return;
    }
    curstate[pos]=1;
    if(pos+3<=m-1) CalStates(pos+3);
    else CalStates(m);
    curstate[pos]=0;
    CalStates(pos+1);
    return;
}

int main()
{
    cin>>n>>m;
    char input;
    for(int r=0;r<n;r++)
    {
        atlas[r]=0;
        for(int c=0;c<m;c++)
        {
            cin>>input;
            atlas[r]+=input=='H'?1:0;
            if(c!=m-1) atlas[r]<<=1;
        }
    }
    memset(curstate,0,sizeof(curstate));
    memset(dp,-1,sizeof(dp));
    CalStates(0);
    maxcannon=0;
    for(int s=0;s<num;s++)
    {
         if(rowstate[s].state&atlas[0]) continue;
         dp[0][s][0]=rowstate[s].cannon;
         if(n==1) maxcannon=max(maxcannon,dp[0][s][0]);
    }
    for(int r=1;r<n;r++)
    {
        for(int scur=0;scur<num;scur++)
        {
            if(rowstate[scur].state&atlas[r]) continue;
            for(int sprev=0;sprev<num;sprev++)
            {
                if(rowstate[sprev].state&atlas[r-1]) continue;
                if(rowstate[scur].state&rowstate[sprev].state)continue;
                if(r==1) {dp[1][scur][sprev]=dp[0][sprev][0]+rowstate[scur].cannon;}
                else
                {
                    dp[r][scur][sprev]=0;
                    for(int spprev=0;spprev<num;spprev++)
                    {
                        if(rowstate[spprev].state&atlas[r-2]) continue;
                        if(rowstate[scur].state&rowstate[spprev].state)continue;
                        if(rowstate[sprev].state&rowstate[spprev].state)continue;
                        dp[r][scur][sprev]=max(dp[r][scur][sprev],dp[r-1][sprev][spprev]+rowstate[scur].cannon);
                    }
                }
                if(r==n-1)maxcannon=max(maxcannon,dp[n-1][scur][sprev]);
            }
        }
    }
    cout<<maxcannon<<endl;
    return 0;
}
