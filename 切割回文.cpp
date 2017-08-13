///切割回文 (POJ 4122)
/*
描述
阿福最近对回文串产生了非常浓厚的兴趣。
如果一个字符串从左往右看和从右往左看完全相同的话，那么就认为这个串是一个回文串。
例如，“abcaacba”是一个回文串，“abcaaba”则不是一个回文串。
阿福现在强迫症发作，看到什么字符串都想要把它变成回文的。阿福可以通过切割字符串，使得切割完之后得到的子串都是回文的。
现在阿福想知道他最少切割多少次就可以达到目的。
例如，对于字符串“abaacca”，最少切割一次，就可以得到“aba”和“acca”这两个回文子串。

输入
输入的第一行是一个整数 T (T <= 20) ，表示一共有 T 组数据。
接下来的 T 行，每一行都包含了一个长度不超过的 1000 的字符串，且字符串只包含了小写字母。
输出
对于每组数据，输出一行。该行包含一个整数，表示阿福最少切割的次数，使得切割完得到的子串都是回文的。
样例输入
3
abaacca
abcd
abcba
样例输出
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

inline int IsPalindrome(int st,int ed)  //原来取substr传string，效率相差100倍以上！
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
