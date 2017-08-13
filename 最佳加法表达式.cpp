///��Ѽӷ����ʽ (OJ 13295)
/*
����
����n��1��9�����֣�Ҫ��������֮��ڷ�m���Ӻ�(�Ӻ����߱��������֣���ʹ�����õ��ļӷ����ʽ��ֵ��С���������ֵ��
���磬��1234�аڷ�1���Ӻţ���õİڷ�����12+34,��Ϊ36

����
�в�����15������
ÿ���������С���һ��������m����ʾ��m���Ӻ�Ҫ��( 0<=m<=50)
�ڶ��������ɸ����֡���������n������50,�� m <= n-1
���
��ÿ�����ݣ������С�ӷ����ʽ��ֵ
��������
2
123456
1
123456
4
12345
�������
102
579
15
��ʾ
Ҫ�õ��߾��ȼ��㣬�������������long long ��װ���µĴ�����������ģ������ʽ�İ취���д������ļӷ���
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int LargeCompare(string a,string b)
{
    if(a.length()!=b.length())
    {
        return a.length()<b.length()?1:-1;
    }
    else
    {
        for(unsigned int pos=0;pos<a.length()-1;pos++)
        {
            if(a[pos]!=b[pos])
            {
                return a[pos]<b[pos]?1:-1;
            }
        }
        return 0;
    }
}

string Largesum(string a,string b)
{
    int c=0;
    unsigned int pos;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a.length()<b.length()) swap(a,b);
    for(pos=0;pos<a.length();pos++)
    {
        if(pos<b.length())
        {
            c+=a[pos]+b[pos]-2*'0';
            a[pos]=c%10+'0';
            c=c/10;
        }
        else
        {
            c+=a[pos]-'0';
            a[pos]=c%10+'0';
            c=c/10;
            if(c==0) break;
        }
    }
    if(c!=0) {a.resize(a.length()+1);a[pos]=c+'0';}
    reverse(a.begin(),a.end());
    return a;
}

int main()
{
    int n,len,curn,curpos,div;
    string num,temp;
    while(cin>>n)
    {
        cin>>num;
        len=num.length();
        string dp[len][n+1];
        for(curpos=0;curpos<len;curpos++)
        {
            dp[curpos][0]=num.substr(0,curpos+1);
            //cout<<"0"<<" "<<curpos<<" "<<dp[curpos][0]<<endl;
        }
        for(curn=1;curn<=n;curn++)
        {
            for(curpos=curn;curpos<len;curpos++)
            {
                dp[curpos][curn]=num.substr(0,curpos+1);
                for(div=curpos-1;div>=0;div--)
                {
                    if(div<curn-1) continue;
                    temp=Largesum(dp[div][curn-1],num.substr(div+1,curpos-div));
                    //cout<<"    "<<div<<" "<<temp<<endl;
                    if(LargeCompare(temp,dp[curpos][curn])==1) dp[curpos][curn]=temp;
                }
                //cout<<curn<<" "<<curpos<<" "<<dp[curpos][curn]<<endl;
            }
        }
        cout<<dp[len-1][n]<<endl;
    }
    return 0;
}
