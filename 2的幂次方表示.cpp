///2的幂次方表示 (OJ8758,NOIP1998)
/*
描述
任何一个正整数都可以用2的幂次方表示。
同时约定方次用括号来表示，即ab可表示为a(b)。由此可知，137可表示为：2(7)+2(3)+2(0)
进一步137可表示为：2(2(2)+2+2(0))+2(2+2(0))+2(0)
又如：1315=210+28+25+2+1
所以1315最后可表示为：2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

输入
一个正整数n（n≤20000）。

输出
一行，符合约定的n的0，2表示（在表示中不能有空格）。
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int,string> cache;

string biexp(int n)
{
    if(cache.find(n)!=cache.end()) return cache[n];
    string res="";
    for(int t=0;n>0;t++)
    {
        if(n%2==1)
        {
            if(t>=2)
            {
                if(!res.empty())
                    res="2("+biexp(t)+")+"+res;
                else res="2("+biexp(t)+")";
            }
            else if(t==0)
            {
                if(!res.empty())
                    res="2(0)+"+res;
                else res="2(0)";
            }
            else if(t==1)
            {
                if(!res.empty())
                    res="2+"+res;
                else res="2";
            }
        }
        n=n/2;
    }
    cache[n]=res;
    return res;
}

int main()
{
    cache[1]="2(0)";
    cache[2]="2";
    int n;
    cin>>n;
    cout<<biexp(n)<<endl;
    return 0;
}
