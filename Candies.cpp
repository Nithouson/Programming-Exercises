///Candies (POJ 3424)
///Dijkstra Algorithm
/*
描述
During the kindergarten days, flymouse was the monitor of his class.
Occasionally the head-teacher brought the kids of flymouse’s class a large bag of candies and had flymouse distribute them.
All the kids loved candies very much and often compared the numbers of candies they got with others.
A kid A could had the idea that though it might be the case that another kid B was better than him in some aspect and therefore had a reason for deserving more candies than he did, he should never get a certain number of candies fewer than B did no matter how many candies he actually got, otherwise he would feel dissatisfied and go to the head-teacher to complain about flymouse’s biased distribution.
snoopy shared class with flymouse at that time.
flymouse always compared the number of his candies with that of snoopy’s.
He wanted to make the difference between the numbers as large as possible while keeping every kid satisfied.
Now he had just got another bag of candies from the head-teacher, what was the largest difference he could make out of it?

输入
The input contains a single test cases. The test cases starts with a line with two integers N and M not exceeding 30 000 and 150 000 respectively.
N is the number of kids in the class and the kids were numbered 1 through N.
snoopy and flymouse were always numbered 1 and N.
Then follow M lines each holding three integers A, B and c in order, meaning that kid A believed that kid B should never get over c candies more than he did.

输出
Output one line with only the largest difference desired. The difference is guaranteed to be finite.

样例输入
2 2
1 2 5
2 1 4
样例输出
5
*/


#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> edge;

class Comp
{
public:
    bool operator()(edge a,edge b)
    {
        return a.second>b.second;
    }
};

int main()
{
    int N,M,a,b,c;
    while(cin>>N>>M)
    {
        vector<edge>graph[N+1];
        int finished[N+1];
        memset(finished,0,sizeof(finished));
        for(int i=0;i<M;i++)
        {
            cin>>a>>b>>c;
            graph[a].push_back(edge(b,c));
        }
        priority_queue<edge,deque<edge>,Comp> Dijkstra;
        Dijkstra.push(edge(1,0));
        int cur,curdis;
        while(!Dijkstra.empty())
        {
            cur=Dijkstra.top().first;
            curdis=Dijkstra.top().second;
            Dijkstra.pop();
            finished[cur]=1;
            if(cur==N) break;
            vector<edge>::iterator p;
            for(p=graph[cur].begin();p!=graph[cur].end();p++)
            {
                if(finished[(*p).first]==0)
                {
                    Dijkstra.push(edge((*p).first,curdis+(*p).second));
                }
            }
        }
        cout<<curdis<<endl;
    }

    return 0;
}
