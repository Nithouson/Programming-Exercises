///滑雪 (POJ1088)
/*描述
Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。
样例输入
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出
25
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> intpair;
bool Comp(intpair a,intpair b)
{
    return a.first<b.first;
}

int main()
{
    int r,c,i,j;
    cin>>r>>c;
    int height;
    int cache[r*c];
    memset(cache,0,sizeof(cache));
    int DEM[r*c];
    pair<int,int> seq[r*c];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>height;
            DEM[i*c+j]=height;
            seq[i*c+j]=make_pair(height,i*c+j);
        }
    }
    sort(seq,seq+r*c,Comp);
    int pos,curr,curc,maxroute=0;
    for(int p=0;p<r*c;p++)
    {
        pos=seq[p].second;
        curr=pos/c;
        curc=pos%c;
        cache[pos]=1;
        if(curr-1>=0&&DEM[pos]>DEM[(curr-1)*c+curc])
        {
            if(cache[(curr-1)*c+curc]+1>cache[pos]) cache[pos]=cache[(curr-1)*c+curc]+1;
        }
        if(curr+1<r&&DEM[pos]>DEM[(curr+1)*c+curc])
        {
            if(cache[(curr+1)*c+curc]+1>cache[pos]) cache[pos]=cache[(curr+1)*c+curc]+1;
        }
        if(curc-1>=0&&DEM[pos]>DEM[curr*c+curc-1])
        {
            if(cache[curr*c+curc-1]+1>cache[pos]) cache[pos]=cache[curr*c+curc-1]+1;
        }
        if(curc+1<c&&DEM[pos]>DEM[curr*c+curc+1])
        {
            if(cache[curr*c+curc+1]+1>cache[pos]) cache[pos]=cache[curr*c+curc+1]+1;
        }
        if(cache[pos]>maxroute) maxroute=cache[pos];
        //cout<<curr<<" "<<curc<<" "<<DEM[pos]<<" "<<cache[pos]<<endl;
    }
    cout<<maxroute;
    return 0;
}
