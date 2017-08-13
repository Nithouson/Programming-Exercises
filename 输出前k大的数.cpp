///输出前k大的数 (OJ 7617)
/*
描述
给定一个数组，统计前k大的数并且把这k个数从大到小输出。
输入
第一行包含一个整数n，表示数组的大小。n < 100000。
第二行包含n个整数，表示数组的元素，整数之间以一个空格分开。每个整数的绝对值不超过100000000。
第三行包含一个整数k。k < n。
输出
从大到小输出前k大的数，每个数一行。
样例输入
10
4 5 6 9 8 7 1 2 3 0
5
样例输出
9
8
7
6
5
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int mypartition(int*a,int s,int e)
{
    int temp=a[s];
    int m=s,n=e;
    while(m<n)
    {
        while(a[n]<temp&&m<n) n--;
        a[m]=a[n];
        if(m<n)m++;
        if(m>=n) break;
        while(a[m]>temp&&m<n) m++;
        a[n]=a[m];
        if(m<n) n--;
    }
    a[m]=temp;
    return m;
}

int main()
{
    int n,i,k;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    int p=0,q=n-1,cpos;
    while(true)
    {
        cpos=mypartition(a,p,q);
        if(cpos==k||cpos==k-1) break;
        else if(cpos<=k-2) {p=cpos+1;}
        else q=cpos-1;
    }
    sort(a,a+k,greater<int>());
    for(i=0;i<k;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
