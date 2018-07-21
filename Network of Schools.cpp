///Network of Schools (POJ 1236)
///Tarjan Algorithm
/*
描述
A number of schools are connected to a computer network.
Agreements have been developed among those schools:
each school maintains a list of schools to which it distributes software (the “receiving schools”).
Note that if B is in the distribution list of school A, then A does not necessarily appear in the list of school B
You are to write a program that computes the minimal number of schools
that must receive a copy of the new software in order for the software
to reach all schools in the network according to the agreement (Subtask A).
As a further task, we want to ensure that by sending the copy of new software to an arbitrary school,
this software will reach all schools in the network.
To achieve this goal we may have to extend the lists of receivers by new members.
Compute the minimal number of extensions that have to be made so that whatever school
we send the new software to, it will reach all other schools (Subtask B).
One extension means introducing one new member into the list of receivers of one school.
输入
The first line contains an integer N: the number of schools in the network (2 <= N <= 100).
The schools are identified by the first N positive integers.
Each of the next N lines describes a list of receivers.
The line i+1 contains the identifiers of the receivers of school i.
Each list ends with a 0. An empty list contains a 0 alone in the line.
输出
Your program should write two lines to the standard output.
The first line should contain one positive integer: the solution of subtask A.
The second line should contain the solution of subtask B.
样例输入
5
2 4 3 0
4 5 0
0
0
1 0
样例输出
1
2
*/


#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> graph[101];
stack<int> Tarjanstack;
int color[101],dfn[101],low[101],mytime=0,branch=1;

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
    int i,input;
    scanf("%d",&N);
    memset(color,-1,sizeof(color));
    for(i=1;i<=N;i++)
    {
        scanf("%d",&input);
        while(input!=0)
        {
            graph[i].push_back(input);
            scanf("%d",&input);
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(color[i]==-1) Tarjan(i);
    }
    int in[branch],out[branch],noin=0,noout=0;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(i=1;i<=N;i++)
    {
        vector<int>::iterator p;
        for(p=graph[i].begin();p!=graph[i].end();p++)
        {
            if(color[i]!=color[(*p)])
            {
                in[color[(*p)]]=1;
                out[color[i]]=1;
            }
        }
    }
    for(int t=1;t<branch;t++)
    {
        if(in[t]==0) noin++;
        if(out[t]==0) noout++;
    }
    cout<<noin<<endl;
    if(branch==2)
        cout<<"0"<<endl;
    else
        cout<<max(noin,noout)<<endl;
    return 0;
}
