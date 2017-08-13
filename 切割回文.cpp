///�и���� (POJ 4122)
/*
����
��������Ի��Ĵ������˷ǳ�Ũ�����Ȥ��
���һ���ַ����������ҿ��ʹ���������ȫ��ͬ�Ļ�����ô����Ϊ�������һ�����Ĵ���
���磬��abcaacba����һ�����Ĵ�����abcaaba������һ�����Ĵ���
��������ǿ��֢����������ʲô�ַ�������Ҫ������ɻ��ĵġ���������ͨ���и��ַ�����ʹ���и���֮��õ����Ӵ����ǻ��ĵġ�
���ڰ�����֪���������и���ٴξͿ��ԴﵽĿ�ġ�
���磬�����ַ�����abaacca���������и�һ�Σ��Ϳ��Եõ���aba���͡�acca�������������Ӵ���

����
����ĵ�һ����һ������ T (T <= 20) ����ʾһ���� T �����ݡ�
�������� T �У�ÿһ�ж�������һ�����Ȳ������� 1000 ���ַ��������ַ���ֻ������Сд��ĸ��
���
����ÿ�����ݣ����һ�С����а���һ����������ʾ���������и�Ĵ�����ʹ���и���õ����Ӵ����ǻ��ĵġ�
��������
3
abaacca
abcd
abcba
�������
1
3
0
*/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 1000
using namespace std;
string str;
int cache[MAX];

inline int IsPalindrome(int st,int ed)  //ԭ��ȡsubstr��string��Ч�����100�����ϣ�
{
    int len=ed-st+1;
    for(int pos=0;pos<=(len-1)/2;pos++)
    {
        if(str[st+pos]!=str[st+len-1-pos]){return 0;}
    }
    return 1;
}

int leastdiv(int st,int ed)
{
    if(st==ed) return 0;
    int res=ed-st,pos=ed,cur;
    for(;pos>=st;pos--)
    {
        if(IsPalindrome(st,pos))
        {
            if(pos==ed) cur=0;
            else cur=cache[pos+1]+1;
            res=res>cur?cur:res;
        }
    }
    cache[st]=res;
    //cout<<st<<" "<<ed<<" "<<res<<endl;
    return res;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(cache,-1,sizeof(cache));
        cin>>str;
        int len=str.length();
        for(int pos=len-1;pos>=0;pos--)
        {
            cache[pos]=leastdiv(pos,len-1);
        }
        cout<<cache[0]<<endl;
    }
    return 0;
}
