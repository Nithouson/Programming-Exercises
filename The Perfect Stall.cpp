///The Perfect Stall (POJ 1274)
///Hungary Algorithm
/*
描述
Farmer John completed his new barn just last week, complete with all the latest milking technology.
Unfortunately, due to engineering problems, all the stalls in the new barn are different.
For the first week, Farmer John randomly assigned cows to stalls,
but it quickly became clear that any given cow was only willing to produce milk in certain stalls.
For the last week, Farmer John has been collecting data on which cows are willing to produce milk
in which stalls. A stall may be only assigned to one cow, and, of course,
a cow may be only assigned to one stall.
Given the preferences of the cows, compute the maximum number of milk-producing assignments
of cows to stalls that is possible.
输入
The input includes several cases.
For each case, the first line contains two integers, N (0 <= N <= 200) and M (0 <= M <= 200).
N is the number of cows that Farmer John has and M is the number of stalls in the new barn.
Each of the following N lines corresponds to a single cow.
The first integer (Si) on the line is the number of stalls that the cow is willing to produce milk
in (0 <= Si <= M). The subsequent Si integers on that line are the stalls in which that cow is
willing to produce milk. The stall numbers will be integers in the range (1..M), and no stall
will be listed twice for a given cow.
输出
For each case, output a single line with a single integer,
the maximum number of milk-producing stall assignments that can be made.
样例输入
5 5
2 2 5
3 2 3 4
2 1 5
3 1 2 5
1 2
样例输出
4
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N,M;
short g[201][201];
short matchC[201],matchS[201];
short visited[201];

bool Augmenting_Path(int i)
{
    int j;
    for(j=1;j<=M;j++)
    {
        if(g[i][j]==0) continue;
        if(visited[j]==1) continue;
        visited[j]=1;
        if(matchS[j]==0||Augmenting_Path(matchS[j]))
        {
            matchC[i]=j;
            matchS[j]=i;
            return true;
        }
    }
    return false;
}


int main()
{
    int i,j,cow,id,pairs;
    while(scanf("%d %d",&N,&M)!=EOF)
    {
        pairs=0;
        memset(g,0,sizeof(g));
        memset(matchC,0,sizeof(matchC));
        memset(matchS,0,sizeof(matchS));
        for(i=1;i<=N;i++)
        {
            scanf("%d",&cow);
            for(j=0;j<cow;j++)
            {
                scanf("%d",&id);
                g[i][id]=1;
            }
        }
        for(i=1;i<=N;i++)
        {
            memset(visited,0,sizeof(visited));
            if(Augmenting_Path(i)){pairs++;}
        }
        cout<<pairs<<endl;
    }
    return 0;
}
