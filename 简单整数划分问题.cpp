///�򵥵�������������(POJ 4117)
/*
����
��������n ��ʾ��һϵ��������֮�ͣ�n=n1+n2+��+nk, ����n1>=n2>=��>=nk>=1 ��k>=1 ��
������n �����ֱ�ʾ��Ϊ������n �Ļ��֡�������n �Ĳ�ͬ�Ļ��ָ�����Ϊ������n �Ļ�������

����
��׼���������������������ݡ�ÿ�����������һ������N(0 < N <= 50)��
���
����ÿ��������ݣ����N�Ļ�������
��������
5
�������
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
