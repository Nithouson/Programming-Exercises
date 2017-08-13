///��ѩ (POJ1088)
/*����
Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������Ļ��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����
����
����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
���
��������ĳ��ȡ�
��������
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
�������
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
