///硬币 (POJ 4120)
/*
描述
宇航员Bob有一天来到火星上，他有收集硬币的习惯。
于是他将火星上所有面值的硬币都收集起来了，一共有n种，每种只有一个：面值分别为a1,a2… an。
Bob在机场看到了一个特别喜欢的礼物，想买来送给朋友Alice，这个礼物的价格是X元。
Bob很想知道为了买这个礼物他的哪些硬币是必须被使用的，即Bob必须放弃收集好的哪些硬币种类。
飞机场不提供找零，只接受恰好X元。
输入
第一行包含两个正整数n和x。（1 <= n <= 200, 1 <= x <= 10000)
第二行从小到大为n个正整数a1, a2, a3 … an （1 <= ai <= x)
输出
第一行是一个整数，即有多少种硬币是必须被使用的。
第二行是这些必须使用的硬币的面值（从小到大排列）。
样例输入
5 18
1 2 3 5 10
样例输出
2
5 10
提示
输入数据将保证给定面值的硬币中至少有一种组合能恰好能够支付X元。
如果不存在必须被使用的硬币，则第一行输出0，第二行输出空行。
*/

#include <iostream>
#include <cstring>
using namespace std;

int value[200];
bool notmust[200];
bool used[200];
short cache[200][10001];

bool traverse(int depth,int total)
{
    if(cache[depth][total]==1)
    {
        for(int i=depth;i<200;i++)
        {
            if(used[i]==false) notmust[i]=true;
        }
        return true;
    }
    if(cache[depth][total]==-1) return false;
    bool succ=false,temp;
    if(depth<0) return false;
    if(value[depth]<total)
    {
        used[depth]=true;
        temp=traverse(depth-1,total-value[depth]);
        if(temp) succ=true;
        used[depth]=false;
        temp=traverse(depth-1,total);
        if(temp) succ=true;
    }
    else if(value[depth]==total)
    {
        used[depth]=true;
        for(int i=0;i<200;i++)
        {
            if(used[i]==false) notmust[i]=true;
        }
        succ=true;
        used[depth]=false;
        traverse(depth-1,total);
    }
    else
    {
        temp=traverse(depth-1,total);
        if(temp) succ=true;
    }
    cache[depth][total]=succ?1:-1;
    return succ;
}

int main()
{
    int n,x,i,coins=0;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
        cin>>value[i];
        notmust[i]=false;
        memset(cache[i],0,sizeof(cache[i]));
    }
    traverse(n-1,x);
    for(i=0;i<n;i++)
    {
        if(notmust[i]==false) coins++;
    }
    cout<<coins<<endl;
    bool spaceflag=false;
    for(i=0;i<n;i++)
    {
        if(notmust[i]==false)
        {
            if(!spaceflag)
            {
                spaceflag=true;
                cout<<value[i];
            }
            else cout<<" "<<value[i];
        }
    }
    cout<<endl;
    return 0;
}
