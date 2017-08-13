///���ǰk����� (OJ 7617)
/*
����
����һ�����飬ͳ��ǰk��������Ұ���k�����Ӵ�С�����
����
��һ�а���һ������n����ʾ����Ĵ�С��n < 100000��
�ڶ��а���n����������ʾ�����Ԫ�أ�����֮����һ���ո�ֿ���ÿ�������ľ���ֵ������100000000��
�����а���һ������k��k < n��
���
�Ӵ�С���ǰk�������ÿ����һ�С�
��������
10
4 5 6 9 8 7 1 2 3 0
5
�������
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
