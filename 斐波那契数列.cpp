///쳲��������� (POJ 2753)
/*����
�Ʋ�����������ָ����������: ���еĵ�һ���͵ڶ�������Ϊ1��������ÿ����������ǰ��2����֮�͡�
����һ��������a��Ҫ��Ʋ����������е�a�����Ƕ��١�
����
��1���ǲ������ݵ�����n���������n�����롣ÿ���������ռ1�У�����һ��������a(1 <= a <= 20)
���
�����n�У�ÿ�������Ӧһ�����롣���Ӧ��һ����������Ϊ�Ʋ����������е�a�����Ĵ�С.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> Fibonacci;
    Fibonacci.push_back(1);
    Fibonacci.push_back(1);
    int n,t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t<=Fibonacci.size()) cout<<*(Fibonacci.begin()+t-1)<<endl;
        else
        {
            for(int u=Fibonacci.size();u<t;u++)
            {
                int newarg=*(Fibonacci.end()-2)+*(Fibonacci.end()-1);
                Fibonacci.push_back(newarg);
            }
            cout<<*(Fibonacci.end()-1)<<endl;
        }
    }
    return 0;
}
