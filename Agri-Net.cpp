///Agri-Net (POJ 1258)
/*
描述
Farmer John has been elected mayor of his town! One of his campaign promises was to bring internet connectivity to all farms in the area. He needs your help, of course.
Farmer John ordered a high speed connection for his farm and is going to share his connectivity with the other farmers. To minimize cost, he wants to lay the minimum amount of optical fiber to connect his farm to all the other farms.
Given a list of how much fiber it takes to connect each pair of farms, you must find the minimum amount of fiber needed to connect them all together. Each farm must connect to some other farm such that a packet can flow from any one farm to any other farm.
The distance between any two farms will not exceed 100,000.
输入
The input includes several cases. For each case, the first line contains the number of farms, N (3 <= N <= 100). The following lines contain the N x N conectivity matrix, where each element shows the distance from on farm to another. Logically, they are N lines of N space-separated integers. Physically, they are limited in length to 80 characters, so some lines continue onto others. Of course, the diagonal will be 0, since the distance from farm i to itself is not interesting for this problem.
输出
For each case, output a single integer length that is the sum of the minimum length of fiber required to connect the entire set of farms.
样例输入
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
样例输出
28
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1000000000
#define USED 2000000000
using namespace std;
int N;
int graph[100][100],dist[100],total;

int main()
{
    int i,j;
    while(cin>>N)
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                cin>>graph[i][j];
            }
        }
        for(int i=0;i<N;i++)
        {
            dist[i]=INF;
        }
        total=0;
        dist[0]=0;
        int nodecount=0,add;
        while(nodecount<N)
        {
            add=min_element(dist,dist+N)-dist;
            total+=dist[add];
            dist[add]=USED;
            nodecount++;
            for(int i=0;i<N;i++)
            {
                if(i==add||dist[i]==USED) continue;
                dist[i]=min(dist[i],graph[add][i]);
            }
        }
        cout<<total<<endl;
    }
    return 0;
}
