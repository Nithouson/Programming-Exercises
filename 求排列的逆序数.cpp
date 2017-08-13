///�����е������� (OJ 7622)
/*
����
��Internet�ϵ��������澭����Ҫ����Ϣ���бȽϣ��������ͨ��ĳ���˶�һЩ��������������������������Ը��ֲ�ͬ��Ϣ����Ȥ���Ӷ�ʵ�ָ��Ի��ķ���
���ڲ�ͬ�����������������������������֮��Ĳ��졣
����1,2,��,n������i1��i2������in��������д���j,k������ j < k �� ij > ik�� ��ô�ͳ�(ij,ik)��������е�һ������
һ�����к�������ĸ�����Ϊ������е���������
�������� 263451 ����8������(2,1),(6,3),(6,4),(6,5),(6,1),(3,1),(4,1),(5,1)����˸����е�����������8��
��Ȼ����1,2,��,n ���ɵ�����n!�������У���С����������0����Ӧ�����о���1,2,��,n��������������n(n-1)/2����Ӧ�����о���n,(n-1),��,2,1��
������Խ���������ԭʼ���еĲ���Ⱦ�Խ��
�ָ���1,2,��,n��һ�����У���������������

����
��һ����һ������n����ʾ��������n������n <= 100000)��
�ڶ�����n����ͬ����������֮���Կո��������ʾ�����С�
���
��������е���������
��������
6
2 6 3 4 5 1
�������
8
��ʾ
1. ���ö��ֹ鲢�����㷨�����Σ���
2. ע�������ܳ���int�ķ�Χ����Ҫ��long long�洢��
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
