///Ӳ�� (POJ 4120)
/*
����
�ԱBob��һ�����������ϣ������ռ�Ӳ�ҵ�ϰ�ߡ�
��������������������ֵ��Ӳ�Ҷ��ռ������ˣ�һ����n�֣�ÿ��ֻ��һ������ֵ�ֱ�Ϊa1,a2�� an��
Bob�ڻ���������һ���ر�ϲ��������������͸�����Alice���������ļ۸���XԪ��
Bob����֪��Ϊ�����������������ЩӲ���Ǳ��뱻ʹ�õģ���Bob��������ռ��õ���ЩӲ�����ࡣ
�ɻ������ṩ���㣬ֻ����ǡ��XԪ��
����
��һ�а�������������n��x����1 <= n <= 200, 1 <= x <= 10000)
�ڶ��д�С����Ϊn��������a1, a2, a3 �� an ��1 <= ai <= x)
���
��һ����һ�����������ж�����Ӳ���Ǳ��뱻ʹ�õġ�
�ڶ�������Щ����ʹ�õ�Ӳ�ҵ���ֵ����С�������У���
��������
5 18
1 2 3 5 10
�������
2
5 10
��ʾ
�������ݽ���֤������ֵ��Ӳ����������һ�������ǡ���ܹ�֧��XԪ��
��������ڱ��뱻ʹ�õ�Ӳ�ң����һ�����0���ڶ���������С�
*/

#include <iostream>
#include <cstring>
using namespace std;

int value[200];
bool notmust[200];
bool used[200];
short cache[200][10001];

bool traverse(int depth,int total)
{
    if(cache[depth][total]==1)
    {
        for(int i=depth;i<200;i++)
        {
            if(used[i]==false) notmust[i]=true;
        }
        return true;
    }
    if(cache[depth][total]==-1) return false;
    bool succ=false,temp;
    if(depth<0) return false;
    if(value[depth]<total)
    {
        used[depth]=true;
        temp=traverse(depth-1,total-value[depth]);
        if(temp) succ=true;
        used[depth]=false;
        temp=traverse(depth-1,total);
        if(temp) succ=true;
    }
    else if(value[depth]==total)
    {
        used[depth]=true;
        for(int i=0;i<200;i++)
        {
            if(used[i]==false) notmust[i]=true;
        }
        succ=true;
        used[depth]=false;
        traverse(depth-1,total);
    }
    else
    {
        temp=traverse(depth-1,total);
        if(temp) succ=true;
    }
    cache[depth][total]=succ?1:-1;
    return succ;
}

int main()
{
    int n,x,i,coins=0;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
        cin>>value[i];
        notmust[i]=false;
        memset(cache[i],0,sizeof(cache[i]));
    }
    traverse(n-1,x);
    for(i=0;i<n;i++)
    {
        if(notmust[i]==false) coins++;
    }
    cout<<coins<<endl;
    bool spaceflag=false;
    for(i=0;i<n;i++)
    {
        if(notmust[i]==false)
        {
            if(!spaceflag)
            {
                spaceflag=true;
                cout<<value[i];
            }
            else cout<<" "<<value[i];
        }
    }
    cout<<endl;
    return 0;
}
