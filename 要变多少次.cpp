///要变多少次 (OJ 15282)
/*
描述
0比1小，所以一个串中如果0全在1前面，这个串就比较和谐。
对于一个只包含0和1的串，你每次可以将一个0变成1，或者将一个1变成0。
那么，最少需要变多少次才能把保证所有的0在1前面呢？

输入
第一行是一个整数 T，代表测试数据的组数。(1 ≤ T ≤ 10)
以下T行每行包含一个01串 S 。(1 ≤ |S| ≤ 1000)
输出
对于每组测试数据输出最少需要修改的次数。
样例输入
3
000111
010001
100000
样例输出
0
1
1
*/


#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
string a;
int len;
int cache[1000][1000];
int minstep(int st,int ed)
{
    if(cache[st][ed]>=0) return cache[st][ed];
    int zpos,opos;
    for(zpos=st;zpos<=ed&&a[zpos]=='0';zpos++);
    for(opos=ed;opos>=st&&a[opos]=='1';opos--);
    if(zpos==opos+1) return 0;
    else
    {
        int r1=1+minstep(zpos+1,ed);
        int r2=1+minstep(st,opos-1);
        cache[st][ed]=min(r1,r2);
        return min(r1,r2);
    }

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a;
        len=a.length();
        memset(cache,-1,sizeof(cache));
        cout<<minstep(0,len-1)<<endl;
    }
    return 0;
}
