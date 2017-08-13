///����Ӿ��� (POJ 2766)
/*
��֪����Ĵ�С����Ϊ����������Ԫ�صĺ͡�����һ����������������ҵ����ķǿ�(��С������1 * 1)�Ӿ���

���磬����4 * 4�ľ���

0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

������Ӿ�����

9 2
-4 1
-1 8

����Ӿ���Ĵ�С��15��
����
������һ��N * N�ľ�������ĵ�һ�и���N (0 < N <= 100)���ٺ�����������У����Σ����ȴ����Ҹ�����һ�е�N���������ٴ����Ҹ����ڶ��е�N���������������������е�N2������������֮���ɿհ��ַ��ָ����ո���߿��У�����֪�����������ķ�Χ����[-127, 127]��
���
�������Ӿ���Ĵ�С��
��������
4
0 -2 -7 0 9 2 -6 2
-4 1 -4  1 -1

8  0 -2
�������
15
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N,i,j;
    cin>>N;
    short grid[N][N];
    int sum[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>grid[i][j];
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i==0)
            {
                if(j==0) sum[i][j]=grid[i][j];
                else sum[i][j]=sum[i][j-1]+grid[i][j];
            }
            else
            {
                if(j==0) sum[i][j]=sum[i-1][j]+grid[i][j];
                else sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+grid[i][j];
            }
        }
    }
    int maxsum=-128,cur,ai,aj,bi,bj;
    for(ai=0;ai<N;ai++)
    {
        for(aj=0;aj<N;aj++)
        {
            for(bi=ai;bi<N;bi++)
            {
                for(bj=aj;bj<N;bj++)
                {
                    if(ai==0&&aj==0) cur=sum[bi][bj];
                    else if(ai==0) cur=sum[bi][bj]-sum[bi][aj-1];
                    else if(aj==0) cur=sum[bi][bj]-sum[ai-1][bj];
                    else cur=sum[bi][bj]-sum[ai-1][bj]-sum[bi][aj-1]+sum[ai-1][aj-1];
                    if(cur>maxsum) maxsum=cur;
                }
            }
        }
    }
    cout<<maxsum<<endl;
    return 0;
}
