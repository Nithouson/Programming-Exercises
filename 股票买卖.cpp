///��Ʊ���� (POJ 4121)
/*
����
���Խ��Խ����˶�Ͷ����У�����Ҳ�е��Ķ��ˡ������š������з��գ���������������������������о�һ�¼򻯰�Ĺ�Ʊ�������⡣
���谢���Ѿ�׼ȷԤ�����ĳֻ��Ʊ��δ�� N ��ļ۸���ϣ���������Σ�ʹ�û�õ�������ߡ�
Ϊ�˼�������������ļ��㷽ʽΪ�����ļ۸��ȥ����ļ۸�
ͬһ����Խ��ж�������������ڵ�һ������֮�󣬱���Ҫ��������Ȼ��ſ��Եڶ������롣
���ڣ�������֪���������Ի�ö�������

����
����ĵ�һ����һ������ T (T <= 50) ����ʾһ���� T �����ݡ�
��������ÿ�����ݣ���һ����һ������ N (1 <= N <= 100, 000) ����ʾһ���� N �졣
�ڶ����� N �����ո�ֿ�����������ʾÿ��ù�Ʊ�ļ۸񡣸ù�Ʊÿ��ļ۸�ľ���ֵ�����ᳬ�� 1,000,000 ��
���
����ÿ�����ݣ����һ�С����а���һ����������ʾ�����ܹ���õ���������
��������
3
7
5 14 -2 4 9 3 17
6
6 8 7 4 1 -2
4
18 9 5 2
�������
28
2
0
��ʾ
���ڵ�һ���������������Ե� 1 ���ڵ� 1 �����루�۸�Ϊ 5 ����Ȼ���ڵ� 2 ���������۸�Ϊ 14 ����
�� 2 ���ڵ� 3 �����루�۸�Ϊ -2 ����Ȼ���ڵ� 7 ���������۸�Ϊ 17 ����һ����õ������� (14 - 5) + (17 - (-2)) = 28
���ڵڶ����������������Ե� 1 ���ڵ� 1 �����루�۸�Ϊ 6 ����Ȼ���ڵ� 2 ���������۸�Ϊ 8 ����
�� 2 ����Ȼ�ڵ� 2 �����룬Ȼ���ڵ� 2 ��������һ����õ������� 8 - 6 = 2
���ڵ��������������ڼ۸�һֱ���µ��������������ѡ��һ������֮��Ѹ����������õ��������Ϊ 0
*/

#include <iostream>
#include <cstdio>
#define MAX 100000
using namespace std;

int main()
{
    int N,days,i,price[MAX],dp[MAX],maxelem[MAX],minelem[MAX],maxdp[MAX],input,d,res;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&days);
        d=res=0;
        for(i=0;i<days;i++)
        {
            scanf("%d",&input);//֮ǰ��cin����ʱ
            if(d==0) {price[d]=input;d++;}
            else if(d>=1&&price[d-1]==input) continue; //�۸���ȣ����ؼ�¼����Ϊһ��
            else if(d>=2&&(price[d-2]-price[d-1])*(input-price[d-1])<=0) price[d-1]=input; //�����仯����������ֻ���ͷβ
            else {price[d]=input;d++;}
        }
        //��һ���γ�һ����-�����У��ߵͽ���

        //iΪ��ֵʱ����ӵ�i����ĩβ�����ֵ
        if(price[d-1]>price[d-2]) //���һ��Ϊ��ֵ
        {
            maxelem[d-2]=price[d-1];
            for(i=d-4;i>=0;i-=2)
            {
                maxelem[i]=price[i+1]>maxelem[i+2]?price[i+1]:maxelem[i+2];
            }
        }
        else //���һ��Ϊ��ֵ
        {
            maxelem[d-1]=price[d-1];
            for(i=d-3;i>=0;i-=2)
            {
                maxelem[i]=price[i+1]>maxelem[i+2]?price[i+1]:maxelem[i+2];
            }
        }

        //iΪ��ֵʱ����ӿ�ͷ�𵽵�i������Сֵ
        if(price[0]>price[1]) //��һ��Ϊ��ֵ
        {
            minelem[0]=price[0];
            for(i=2;i<d;i+=2)
            {
                minelem[i]=price[i-1]<minelem[i-2]?price[i-1]:minelem[i-2];
            }
        }
        else //��һ��Ϊ��ֵ
        {
            minelem[1]=price[0];
            for(i=3;i<d;i+=2)
            {
                minelem[i]=price[i-1]<minelem[i-2]?price[i-1]:minelem[i-2];
            }
        }
        //�Է�ֵ������֮ǰ��Сֵʱ�������������������
        //�Թ�ֵ�����㵱�������֮�����ֵʱ����������
        if(price[0]>price[1]){dp[0]=0;}
        else {dp[0]=maxelem[0]-price[0];}
        for(i=1;i<d;i++)
        {
            if(price[i]<price[i-1]) dp[i]=maxelem[i]-price[i];
            else dp[i]=price[i]-minelem[i];
        }

        //�Է�ֵ������֮���ֵ������������ֵ
        if(price[d-1]>price[d-2])
        {
            maxdp[d-1]=0;
            for(i=d-3;i>=0;i-=2)
            {
                maxdp[i]=dp[i+1]>maxdp[i+2]?dp[i+1]:maxdp[i+2];
            }
        }
        else
        {
            maxdp[d-2]=0;
            for(i=d-4;i>=0;i-=2)
            {
                maxdp[i]=dp[i+1]>maxdp[i+2]?dp[i+1]:maxdp[i+2];
            }
        }

        //�������е�һ�������ķ�ֵ��ȡ���������
        if(price[0]>price[1])
        {
            for(i=0;i<d;i+=2)
            {
                res=dp[i]+maxdp[i]>=res?dp[i]+maxdp[i]:res;
            }
        }
        else
        {
            for(i=1;i<d;i+=2)
            {
                res=dp[i]+maxdp[i]>=res?dp[i]+maxdp[i]:res;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
