///最佳加法表达式 (OJ 13295)
/*
描述
给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。
例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36

输入
有不超过15组数据
每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
第二行是若干个数字。数字总数n不超过50,且 m <= n-1
输出
对每组数据，输出最小加法表达式的值
样例输入
2
123456
1
123456
4
12345
样例输出
102
579
15
提示
要用到高精度计算，即用数组来存放long long 都装不下的大整数，并用模拟列竖式的办法进行大整数的加法。
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int LargeCompare(string a,string b)
{
    if(a.length()!=b.length())
    {
        return a.length()<b.length()?1:-1;
    }
    else
    {
        for(unsigned int pos=0;pos<a.length()-1;pos++)
        {
            if(a[pos]!=b[pos])
            {
                return a[pos]<b[pos]?1:-1;
            }
        }
        return 0;
    }
}

string Largesum(string a,string b)
{
    int c=0;
    unsigned int pos;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a.length()<b.length()) swap(a,b);
    for(pos=0;pos<a.length();pos++)
    {
        if(pos<b.length())
        {
            c+=a[pos]+b[pos]-2*'0';
            a[pos]=c%10+'0';
            c=c/10;
        }
        else
        {
            c+=a[pos]-'0';
            a[pos]=c%10+'0';
            c=c/10;
            if(c==0) break;
        }
    }
    if(c!=0) {a.resize(a.length()+1);a[pos]=c+'0';}
    reverse(a.begin(),a.end());
    return a;
}

int main()
{
    int n,len,curn,curpos,div;
    string num,temp;
    while(cin>>n)
    {
        cin>>num;
        len=num.length();
        string dp[len][n+1];
        for(curpos=0;curpos<len;curpos++)
        {
            dp[curpos][0]=num.substr(0,curpos+1);
            //cout<<"0"<<" "<<curpos<<" "<<dp[curpos][0]<<endl;
        }
        for(curn=1;curn<=n;curn++)
        {
            for(curpos=curn;curpos<len;curpos++)
            {
                dp[curpos][curn]=num.substr(0,curpos+1);
                for(div=curpos-1;div>=0;div--)
                {
                    if(div<curn-1) continue;
                    temp=Largesum(dp[div][curn-1],num.substr(div+1,curpos-div));
                    //cout<<"    "<<div<<" "<<temp<<endl;
                    if(LargeCompare(temp,dp[curpos][curn])==1) dp[curpos][curn]=temp;
                }
                //cout<<curn<<" "<<curpos<<" "<<dp[curpos][curn]<<endl;
            }
        }
        cout<<dp[len-1][n]<<endl;
    }
    return 0;
}
