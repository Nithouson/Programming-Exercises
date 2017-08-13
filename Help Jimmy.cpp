///Help Jimmy (POJ 2978)
/*
描述
"Help Jimmy" 是场景上完成的游戏：
场景中包括多个长度和高度各不相同的平台。地面是最低的平台，高度为零，长度无限。
Jimmy老鼠在时刻0从高于所有平台的某处开始下落，它的下落速度始终为1米/秒。
当Jimmy落到某个平台上时，游戏者选择让它向左还是向右跑，它跑动的速度也是1米/秒。
当Jimmy跑到平台的边缘时，开始继续下落。Jimmy每次下落的高度不能超过MAX米，不然就会摔死，游戏也会结束。
设计一个程序，计算Jimmy到底地面时可能的最早时间。
输入
第一行是测试数据的组数t（0 <= t <= 20）。每组测试数据的第一行是四个整数N，X，Y，MAX，用空格分隔。
N是平台的数目（不包括地面），X和Y是Jimmy开始下落的位置的横竖坐标，MAX是一次下落的最大高度。
接下来的N行每行描述一个平台，包括三个整数，X1[i]，X2[i]和H[i]。H[i]表示平台的高度，X1[i]和X2[i]表示平台左右端点的横坐标。
1 <= N <= 1000，-20000 <= X, X1[i], X2[i] <= 20000，0 < H[i] < Y <= 20000（i = 1..N）。所有坐标的单位都是米。
Jimmy的大小和平台的厚度均忽略不计。如果Jimmy恰好落在某个平台的边缘，被视为落在平台上。所有的平台均不重叠或相连。
测试数据保证问题一定有解。
输出
对输入的每组测试数据，输出一个整数，Jimmy到底地面时可能的最早时间。
样例输入
1
3 8 17 20
0 10 8
0 10 13
4 14 3
样例输出
23
*/


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct platform
{
    int lx,rx;
    int h;
};

bool Comp(platform a,platform b)
{
    if(a.h!=b.h) return a.h<b.h;
    else return a.lx<b.lx;
}

int main()
{
    int T,n,x,y,maxh;
    cin>>T;
    while(T--)
    {
        int i,j,ttime=0;
        cin>>n>>x>>y>>maxh;
        platform step[n];
        for(i=0;i<n;i++)
        {
            cin>>step[i].lx>>step[i].rx>>step[i].h;
        }
        sort(step,step+n,Comp);
        int ltime[n],rtime[n];
        memset(ltime,-1,sizeof(ltime));
        memset(rtime,-1,sizeof(rtime));
        for(i=0;i<n;i++)
        {
            for(j=i-1;j>=0&&step[i].h-step[j].h<=maxh;j--)
            {
                if(step[i].lx>=step[j].lx&&step[i].lx<=step[j].rx)
                {
                    ltime[i]=min(ltime[j]+step[i].lx-step[j].lx,rtime[j]+step[j].rx-step[i].lx);
                    break;
                }
            }
            for(j=i-1;j>=0&&step[i].h-step[j].h<=maxh;j--)
            {
                if(step[i].rx>=step[j].lx&&step[i].rx<=step[j].rx)
                {
                    rtime[i]=min(ltime[j]+step[i].rx-step[j].lx,rtime[j]+step[j].rx-step[i].rx);
                    break;
                }
            }
            if(ltime[i]==rtime[i]&&ltime[i]==-1)
            {
                if(step[i].h>maxh) ltime[i]=rtime[i]=1<<30;
                else ltime[i]=rtime[i]=0;
            }
            else if(ltime[i]==-1)
            {
                if(step[i].h>maxh) ltime[i]=rtime[i]+step[i].rx-step[i].lx;
                else {ltime[i]=0;rtime[i]=min(rtime[i],step[i].rx-step[i].lx);}
            }
            else if(rtime[i]==-1)
            {
                if(step[i].h>maxh) rtime[i]=ltime[i]+step[i].rx-step[i].lx;
                else {rtime[i]=0;ltime[i]=min(ltime[i],step[i].rx-step[i].lx);}
            }
            else if(abs(rtime[i]-ltime[i])>step[i].rx-step[i].lx)
            {
                if(rtime[i]>ltime[i]) rtime[i]=ltime[i]+step[i].rx-step[i].lx;
                else ltime[i]=rtime[i]+step[i].rx-step[i].lx;
            }
        }
        for(i=n-1;i>=0&&y-step[i].h<=maxh;i--)
        {
            if(x>=step[i].lx&&x<=step[i].rx)
            {
                ttime=min(ltime[i]+x-step[i].lx,rtime[i]+step[i].rx-x);
                break;
            }
        }
        ttime+=y;
        cout<<ttime<<endl;
    }
    return 0;
}
