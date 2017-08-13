///Ҫ����ٴ� (OJ 15282)
/*
����
0��1С������һ���������0ȫ��1ǰ�棬������ͱȽϺ�г��
����һ��ֻ����0��1�Ĵ�����ÿ�ο��Խ�һ��0���1�����߽�һ��1���0��
��ô��������Ҫ����ٴβ��ܰѱ�֤���е�0��1ǰ���أ�

����
��һ����һ������ T������������ݵ�������(1 �� T �� 10)
����T��ÿ�а���һ��01�� S ��(1 �� |S| �� 1000)
���
����ÿ������������������Ҫ�޸ĵĴ�����
��������
3
000111
010001
100000
�������
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
