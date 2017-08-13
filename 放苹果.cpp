///放苹果 (POJ 1664)
/*描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
输入
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
输出
对输入的每组数据M和N，用一行输出相应的K。
样例输入
1
7 3
样例输出
8
*/

#include <iostream>
#include <cmath>
using namespace std;

int Arrangement(int m,int n)
{
    if(n==1||m==0) return 1;
    else if(m<0) return 0;
    else return Arrangement(m,n-1)+Arrangement(m-n,n);
}

int main()
{
    int m,n,t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>m>>n;
        cout<<Arrangement(m,n)<<endl;
    }
    return 0;
}
