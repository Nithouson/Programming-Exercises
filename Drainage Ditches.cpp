///Drainage Ditches (POJ 1273)
///Network Flow
/*
描述
Every time it rains on Farmer John's fields, a pond forms over Bessie's favorite clover patch. This means that the clover is covered by water for awhile and takes quite a long time to regrow. Thus, Farmer John has built a set of drainage ditches so that Bessie's clover patch is never covered in water. Instead, the water is drained to a nearby stream. Being an ace engineer, Farmer John has also installed regulators at the beginning of each ditch, so he can control at what rate water flows into that ditch.
Farmer John knows not only how many gallons of water each ditch can transport per minute but also the exact layout of the ditches, which feed out of the pond and into each other and stream in a potentially complex network.
Given all this information, determine the maximum rate at which water can be transported out of the pond and into the stream. For any given ditch, water flows in only one direction, but there might be a way that water can flow in a circle.
输入
The input includes several cases. For each case, the first line contains two space-separated integers, N (0 <= N <= 200) and M (2 <= M <= 200). N is the number of ditches that Farmer John has dug. M is the number of intersections points for those ditches. Intersection 1 is the pond. Intersection point M is the stream. Each of the following N lines contains three integers, Si, Ei, and Ci. Si and Ei (1 <= Si, Ei <= M) designate the intersections between which this ditch flows. Water will flow through this ditch from Si to Ei. Ci (0 <= Ci <= 10,000,000) is the maximum rate at which water will flow through the ditch.
输出
For each case, output a single integer, the maximum rate at which water may emptied from the pond.
样例输入
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
样例输出
50
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
int graph[201][201];
int level[201];

int bfs()
{
    queue<int> bfsqueue;
    bfsqueue.push(1);
    memset(level,-1,sizeof(level));
    level[1]=0;
    int cur;
    while(!bfsqueue.empty())
    {
        cur=bfsqueue.front();
        bfsqueue.pop();
        if(cur==m) return true;
        for(int p=1;p<=m;p++)
        {
            if(graph[cur][p]>0&&level[p]==-1)
            {
                level[p]=level[cur]+1;
                bfsqueue.push(p);
            }
        }
    }
    return false;
}

int Dinic()
{
    int netflow=0;
    while(bfs())
    {
        deque<int> dfs;
        dfs.push_back(1);
        int cur;
        int visited[m+1];
        memset(visited,0,sizeof(visited));
        visited[1]=1;
        while(!dfs.empty())
        {
            cur=dfs.back();
            if(cur==m)
            {
                int minflow=10000001;
                int tvpoint;
                deque<int>::iterator q;
                int s,t;
                for(q=++dfs.begin();q!=dfs.end();q++)
                {
                    s=*(q-1);t=*q;
                    if(graph[s][t]<minflow)
                    {
                        minflow=graph[s][t];
                        tvpoint=s;
                    }
                }
                netflow+=minflow;
                bool pop=true;
                for(q=--dfs.end();q!=dfs.begin();q--)
                {
                    s=*(q-1);t=*q;
                    graph[s][t]-=minflow;
                    graph[t][s]+=minflow;
                    if(pop)
                    {
                        dfs.pop_back();
                        visited[t]=0;
                    }
                    if(s==tvpoint) pop=false;
                }
            }
            else
            {
                int p;
                for(p=1;p<=m;p++)
                {
                    if(graph[cur][p]>0&&level[p]>level[cur]&&visited[p]==0)
                    {
                        visited[p]=1;
                        dfs.push_back(p);
                        break;
                    }
                }
                if(p==m+1) dfs.pop_back();
            }
        }
    }
    return netflow;
}

int main()
{
    int i,s,t,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(graph,0,sizeof(graph));
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&s,&t,&c);
            graph[s][t]+=c;
        }
        cout<<Dinic()<<endl;
    }
    return 0;
}
