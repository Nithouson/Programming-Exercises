///简单的整数划分问题(POJ 4117)
/*
描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。正整数n 的不同的划分个数称为正整数n 的划分数。

输入
标准的输入包含若干组测试数据。每组测试数据是一个整数N(0 < N <= 50)。
输出
对于每组测试数据，输出N的划分数。
样例输入
5
样例输出
7
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int f[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==1) f[i][j]=1;
                else if(i<j) f[i][j]=f[i][j-1];
                else
                {
                    f[i][j]=f[i][j-1]+f[i-j][j];
                }
            }
        }
        cout<<f[n][n]<<endl;
    }
    return 0;
}
