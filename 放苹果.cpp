///��ƻ�� (POJ 1664)
/*����
��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ�������K��ʾ��5��1��1��1��5��1 ��ͬһ�ַַ���
����
��һ���ǲ������ݵ���Ŀt��0 <= t <= 20��������ÿ�о�������������M��N���Կո�ֿ���1<=M��N<=10��
���
�������ÿ������M��N����һ�������Ӧ��K��
��������
1
7 3
�������
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
