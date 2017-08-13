///2���ݴη���ʾ (OJ8758,NOIP1998)
/*
����
�κ�һ����������������2���ݴη���ʾ��
ͬʱԼ����������������ʾ����ab�ɱ�ʾΪa(b)���ɴ˿�֪��137�ɱ�ʾΪ��2(7)+2(3)+2(0)
��һ��137�ɱ�ʾΪ��2(2(2)+2+2(0))+2(2+2(0))+2(0)
���磺1315=210+28+25+2+1
����1315���ɱ�ʾΪ��2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

����
һ��������n��n��20000����

���
һ�У�����Լ����n��0��2��ʾ���ڱ�ʾ�в����пո񣩡�
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int,string> cache;

string biexp(int n)
{
    if(cache.find(n)!=cache.end()) return cache[n];
    string res="";
    for(int t=0;n>0;t++)
    {
        if(n%2==1)
        {
            if(t>=2)
            {
                if(!res.empty())
                    res="2("+biexp(t)+")+"+res;
                else res="2("+biexp(t)+")";
            }
            else if(t==0)
            {
                if(!res.empty())
                    res="2(0)+"+res;
                else res="2(0)";
            }
            else if(t==1)
            {
                if(!res.empty())
                    res="2+"+res;
                else res="2";
            }
        }
        n=n/2;
    }
    cache[n]=res;
    return res;
}

int main()
{
    cache[1]="2(0)";
    cache[2]="2";
    int n;
    cin>>n;
    cout<<biexp(n)<<endl;
    return 0;
}
