///求排列的逆序数 (OJ 7622)
/*
描述
在Internet上的搜索引擎经常需要对信息进行比较，比如可以通过某个人对一些事物的排名来估计他（或她）对各种不同信息的兴趣，从而实现个性化的服务。
对于不同的排名结果可以用逆序来评价它们之间的差异。
考虑1,2,…,n的排列i1，i2，…，in，如果其中存在j,k，满足 j < k 且 ij > ik， 那么就称(ij,ik)是这个排列的一个逆序。
一个排列含有逆序的个数称为这个排列的逆序数。
例如排列 263451 含有8个逆序(2,1),(6,3),(6,4),(6,5),(6,1),(3,1),(4,1),(5,1)，因此该排列的逆序数就是8。
显然，由1,2,…,n 构成的所有n!个排列中，最小的逆序数是0，对应的排列就是1,2,…,n；最大的逆序数是n(n-1)/2，对应的排列就是n,(n-1),…,2,1。
逆序数越大的排列与原始排列的差异度就越大。
现给定1,2,…,n的一个排列，求它的逆序数。

输入
第一行是一个整数n，表示该排列有n个数（n <= 100000)。
第二行是n个不同的正整数，之间以空格隔开，表示该排列。
输出
输出该排列的逆序数。
样例输入
6
2 6 3 4 5 1
样例输出
8
提示
1. 利用二分归并排序算法（分治）；
2. 注意结果可能超过int的范围，需要用long long存储。
*/


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

long long int Revmerge(int* a,int s,int m,int e)
{
    int p=s,q=m+1,cur=0;
    int *temp=new int[e-s+1];
    long long int res=0;
    while(p<=m&&q<=e)
    {
        if(a[p]<a[q])
        {
            temp[cur]=a[p];
            p++;cur++;
            res+=q-m-1;
        }
        else
        {
            temp[cur]=a[q];
            q++;cur++;
        }
    }
    while(p<=m)
    {
        temp[cur]=a[p];
        p++;cur++;
        res+=q-m-1;
    }
    while(q<=e)
    {
        temp[cur]=a[q];
        q++;cur++;
    }
    memcpy(a+s,temp,(e-s+1)*sizeof(int));
    delete[]temp;
    return res;
}

long long int Revpair(int* a,int s,int e)
{
    if(s==e) return 0;
    long long int res=0;
    int m=s+(e-s)/2;
    res+=Revpair(a,s,m);
    res+=Revpair(a,m+1,e);
    res+=Revmerge(a,s,m,e);
    return res;
}

int main()
{
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    cout<<Revpair(a,0,N-1)<<endl;
    return 0;
}
