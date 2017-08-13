///42点 (OJ 10715)
/*
描述
42是：
·组合数学上的第5个卡特兰数
·字符'*'的ASCII码
·钼的原子序数
·6与9的乘积结果的13进制表示
·生命、宇宙以及任何事情的终极答案
·以及……表达式(1+5)/2*(6-4)*7的值
因此，小机器人Marvin发明了这个叫42点的小游戏。在这个游戏中，玩家会获得n个数。
玩家需要使用'+'、'-'、'*'、'/'、'('、')'以及这n个数构成一个合法的中缀表达式，并使得该表达式的值为42。
n个数之间的顺序可以改变。表达式运算过程中只能出现整数。
由于过于抑郁，Marvin无力完成这个游戏，于是来找你帮忙。
你的任务是对于给定的n个数，判断他们是否能根据上述游戏规则算出42。

输入
第一行为一个数n，1<=n<=6。
第二行为n个数，每个数均为[1,13]范围内的整数。
输出
输出一行，若可以算出42则输出“YES”，否则输出“NO”（注意大小写）。
样例输入
6
1 5 2 6 4 7
样例输出
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
