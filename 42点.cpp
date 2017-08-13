///42�� (OJ 10715)
/*
����
42�ǣ�
�������ѧ�ϵĵ�5����������
���ַ�'*'��ASCII��
�����ԭ������
��6��9�ĳ˻������13���Ʊ�ʾ
�������������Լ��κ�������ռ���
���Լ��������ʽ(1+5)/2*(6-4)*7��ֵ
��ˣ�С������Marvin�����������42���С��Ϸ���������Ϸ�У���һ���n������
�����Ҫʹ��'+'��'-'��'*'��'/'��'('��')'�Լ���n��������һ���Ϸ�����׺���ʽ����ʹ�øñ��ʽ��ֵΪ42��
n����֮���˳����Ըı䡣���ʽ���������ֻ�ܳ���������
���ڹ���������Marvin������������Ϸ�������������æ��
��������Ƕ��ڸ�����n�������ж������Ƿ��ܸ���������Ϸ�������42��

����
��һ��Ϊһ����n��1<=n<=6��
�ڶ���Ϊn������ÿ������Ϊ[1,13]��Χ�ڵ�������
���
���һ�У����������42�������YES�������������NO����ע���Сд����
��������
6
1 5 2 6 4 7
�������
YES
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool check(int*arr,int num)
{
    if(num==1) return arr[0]==42;
    else
    {
        int i,j;
        for(i=0;i<num;i++)
        {
            for(j=0;j<i;j++)
            {
                int brr[num];
                memcpy(brr,arr,sizeof(brr));
                brr[j]=brr[i]+brr[j];
                brr[i]=brr[num-1];
                if(check(brr,num-1)) {return true;}

                int crr[num];
                memcpy(crr,arr,sizeof(crr));
                crr[j]=crr[i]*crr[j];
                crr[i]=crr[num-1];
                if(check(crr,num-1)) {return true;}

                if(arr[j]<arr[i]) swap(arr[j],arr[i]);
                int drr[num];
                memcpy(drr,arr,sizeof(drr));
                drr[j]=drr[j]-drr[i];
                drr[i]=drr[num-1];
                if(check(drr,num-1)) {return true;}

                int err[num];
                memcpy(err,arr,sizeof(err));
                if(err[i]!=0&&err[j]%err[i]==0)
                {
                    err[j]=err[j]/err[i];
                    err[i]=err[num-1];
                    if(check(crr,num-1)) return true;
                }
            }
        }
    }
    return false;
}


int main()
{
    int n,i,arr[6];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(check(arr,n))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
