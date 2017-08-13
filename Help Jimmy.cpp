///Help Jimmy (POJ 2978)
/*
����
"Help Jimmy" �ǳ�������ɵ���Ϸ��
�����а���������Ⱥ͸߶ȸ�����ͬ��ƽ̨����������͵�ƽ̨���߶�Ϊ�㣬�������ޡ�
Jimmy������ʱ��0�Ӹ�������ƽ̨��ĳ����ʼ���䣬���������ٶ�ʼ��Ϊ1��/�롣
��Jimmy�䵽ĳ��ƽ̨��ʱ����Ϸ��ѡ�����������������ܣ����ܶ����ٶ�Ҳ��1��/�롣
��Jimmy�ܵ�ƽ̨�ı�Եʱ����ʼ�������䡣Jimmyÿ������ĸ߶Ȳ��ܳ���MAX�ף���Ȼ�ͻ�ˤ������ϷҲ�������
���һ�����򣬼���Jimmy���׵���ʱ���ܵ�����ʱ�䡣
����
��һ���ǲ������ݵ�����t��0 <= t <= 20����ÿ��������ݵĵ�һ�����ĸ�����N��X��Y��MAX���ÿո�ָ���
N��ƽ̨����Ŀ�����������棩��X��Y��Jimmy��ʼ�����λ�õĺ������꣬MAX��һ����������߶ȡ�
��������N��ÿ������һ��ƽ̨����������������X1[i]��X2[i]��H[i]��H[i]��ʾƽ̨�ĸ߶ȣ�X1[i]��X2[i]��ʾƽ̨���Ҷ˵�ĺ����ꡣ
1 <= N <= 1000��-20000 <= X, X1[i], X2[i] <= 20000��0 < H[i] < Y <= 20000��i = 1..N������������ĵ�λ�����ס�
Jimmy�Ĵ�С��ƽ̨�ĺ�Ⱦ����Բ��ơ����Jimmyǡ������ĳ��ƽ̨�ı�Ե������Ϊ����ƽ̨�ϡ����е�ƽ̨�����ص���������
�������ݱ�֤����һ���н⡣
���
�������ÿ��������ݣ����һ��������Jimmy���׵���ʱ���ܵ�����ʱ�䡣
��������
1
3 8 17 20
0 10 8
0 10 13
4 14 3
�������
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
