///Popular Cows (POJ 2186)
///Tarjan Algorithm
/*
描述
Every cow's dream is to become the most popular cow in the herd.
In a herd of N (1 <= N <= 10,000) cows, you are given up to M (1 <= M <= 50,000) ordered
pairs of the form (A, B) that tell you that cow A thinks that cow B is popular.
Since popularity is transitive, if A thinks B is popular and B thinks C is popular,
then A will also think that C is popular, even if this is not explicitly specified by an ordered pair
in the input. Your task is to compute the number of cows that are considered popular
by every other cow.
输入
* Line 1: Two space-separated integers, N and M
* Lines 2..1+M: Two space-separated numbers A and B, meaning that A thinks B is popular.
输出
* Line 1: A single integer that is the number of cows who are considered popular by every other cow.
样例输入
3 3
1 2
2 1
2 3
样例输出
1
*/


#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> graph[10001];
stack<int> Tarjanstack;
int color[10001],dfn[10001],low[10001],mytime=0,branch=1;

void Tarjan(int node)
{
    mytime++;
    dfn[node]=mytime;
    low[node]=mytime;
    Tarjanstack.push(node);
    color[node]=0;
    vector<int>::iterator p;
    for(p=graph[node].begin();p!=graph[node].end();p++)
    {
        if(color[(*p)]==-1)
        {
            Tarjan((*p));
            low[node]=min(low[node],low[(*p)]);
        }
        else if(color[(*p)]==0)
        {
            low[node]=min(low[node],dfn[(*p)]);
        }
    }
    if(low[node]==dfn[node])
    {
        color[node]=branch;
        int t=Tarjanstack.top();
        Tarjanstack.pop();
        while(t!=node)
        {
            color[t]=branch;
            t=Tarjanstack.top();
            Tarjanstack.pop();
        }
        branch++;
    }
}

int main()
{
    int M,i,a,b;
    scanf("%d%d",&N,&M);
    memset(color,-1,sizeof(color));
    for(i=1;i<=M;i++)
    {
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    for(int i=1;i<=N;i++)
    {
        if(color[i]==-1) Tarjan(i);
    }
    int out[branch],noout=0;
    memset(out,0,sizeof(out));
    for(i=1;i<=N;i++)
    {
        vector<int>::iterator p;
        for(p=graph[i].begin();p!=graph[i].end();p++)
        {
            if(color[i]!=color[(*p)])
            {
                out[color[i]]=1;
            }
        }
    }
    for(int t=1;t<branch;t++)
    {
        if(out[t]==0)
        {
            if(noout==0)noout=t;
            else {cout<<"0"<<endl;return 0;}
        }
    }
    int res=0;
    for(i=1;i<=N;i++)
    {
        if(color[i]==noout) res++;
    }
    cout<<res<<endl;
    return 0;
}
