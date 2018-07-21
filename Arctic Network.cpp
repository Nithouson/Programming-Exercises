///Arctic Network(POJ 2349)
/*
描述
The Department of National Defence (DND) wishes to connect several northern outposts by a wireless network.
Two different communication technologies are to be used in establishing the network:
every outpost will have a radio transceiver and some outposts will in addition have a satellite channel.
Any two outposts with a satellite channel can communicate via the satellite, regardless of their location.
Otherwise, two outposts can communicate by radio only if the distance between them does not exceed D, which depends of the power of the transceivers.
Higher power yields higher D but costs more.
Due to purchasing and maintenance considerations, the transceivers at the outposts must be identical; that is, the value of D is the same for every pair of outposts.

Your job is to determine the minimum D required for the transceivers. There must be at least one communication path (direct or indirect) between every pair of outposts.
输入
The first line of input contains N, the number of test cases.
The first line of each test case contains 1 <= S <= 100, the number of satellite channels, and S < P <= 500, the number of outposts.
P lines follow, giving the (x,y) coordinates of each outpost in km (coordinates are integers between 0 and 10,000).
输出
For each case, output should consist of a single line giving the minimum D required to connect the network. Output should be specified to 2 decimal points.
样例输入
1
2 4
0 100
0 300
0 600
150 750
样例输出
212.13
*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#define INF 1000000000
#define USED 2000000000
using namespace std;
int xpos[500],ypos[500],graph[500][500],dist[500];

inline int sqrdis(int x1,int x2,int y1,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
    int T,N,K,i,j;
    cin>>T;
    while(T--)
    {
        cin>>K>>N;
        for(i=0;i<N;i++)
        {
            cin>>xpos[i]>>ypos[i];
            dist[i]=INF;
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                graph[i][j]=sqrdis(xpos[i],xpos[j],ypos[i],ypos[j]);
            }
        }
        vector<int> edge;
        dist[0]=0;
        int nodecount=0,add;
        while(nodecount<N)
        {
            add=min_element(dist,dist+N)-dist;
            edge.push_back(dist[add]);
            dist[add]=USED;
            nodecount++;
            for(int i=0;i<N;i++)
            {
                if(i==add||dist[i]==USED) continue;
                dist[i]=min(dist[i],graph[add][i]);
            }
        }
        sort(edge.begin(),edge.end(),greater<double>());
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<sqrt(edge[K==0?0:K-1])<<endl;
    }
    return 0;
}
