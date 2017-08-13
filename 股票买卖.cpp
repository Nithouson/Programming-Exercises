///股票买卖 (POJ 4121)
/*
描述
最近越来越多的人都投身股市，阿福也有点心动了。谨记着“股市有风险，入市需谨慎”，阿福决定先来研究一下简化版的股票买卖问题。
假设阿福已经准确预测出了某只股票在未来 N 天的价格，他希望买卖两次，使得获得的利润最高。
为了计算简单起见，利润的计算方式为卖出的价格减去买入的价格。
同一天可以进行多次买卖。但是在第一次买入之后，必须要先卖出，然后才可以第二次买入。
现在，阿福想知道他最多可以获得多少利润。

输入
输入的第一行是一个整数 T (T <= 50) ，表示一共有 T 组数据。
接下来的每组数据，第一行是一个整数 N (1 <= N <= 100, 000) ，表示一共有 N 天。
第二行是 N 个被空格分开的整数，表示每天该股票的价格。该股票每天的价格的绝对值均不会超过 1,000,000 。
输出
对于每组数据，输出一行。该行包含一个整数，表示阿福能够获得的最大的利润。
样例输入
3
7
5 14 -2 4 9 3 17
6
6 8 7 4 1 -2
4
18 9 5 2
样例输出
28
2
0
提示
对于第一组样例，阿福可以第 1 次在第 1 天买入（价格为 5 ），然后在第 2 天卖出（价格为 14 ）。
第 2 次在第 3 天买入（价格为 -2 ），然后在第 7 天卖出（价格为 17 ）。一共获得的利润是 (14 - 5) + (17 - (-2)) = 28
对于第二组样例，阿福可以第 1 次在第 1 天买入（价格为 6 ），然后在第 2 天卖出（价格为 8 ）。
第 2 次仍然在第 2 天买入，然后在第 2 天卖出。一共获得的利润是 8 - 6 = 2
对于第三组样例，由于价格一直在下跌，阿福可以随便选择一天买入之后迅速卖出。获得的最大利润为 0
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
            scanf("%d",&input);//之前用cin，超时
            if(d==0) {price[d]=input;d++;}
            else if(d>=1&&price[d-1]==input) continue; //价格相等，不必记录，视为一天
            else if(d>=2&&(price[d-2]-price[d-1])*(input-price[d-1])<=0) price[d-1]=input; //单调变化的连续几天只需记头尾
            else {price[d]=input;d++;}
        }
        //这一步形成一个峰-谷序列，高低交错

        //i为谷值时，求从第i个起到末尾的最大值
        if(price[d-1]>price[d-2]) //最后一个为峰值
        {
            maxelem[d-2]=price[d-1];
            for(i=d-4;i>=0;i-=2)
            {
                maxelem[i]=price[i+1]>maxelem[i+2]?price[i+1]:maxelem[i+2];
            }
        }
        else //最后一个为谷值
        {
            maxelem[d-1]=price[d-1];
            for(i=d-3;i>=0;i-=2)
            {
                maxelem[i]=price[i+1]>maxelem[i+2]?price[i+1]:maxelem[i+2];
            }
        }

        //i为峰值时，求从开头起到第i个的最小值
        if(price[0]>price[1]) //第一个为峰值
        {
            minelem[0]=price[0];
            for(i=2;i<d;i+=2)
            {
                minelem[i]=price[i-1]<minelem[i-2]?price[i-1]:minelem[i-2];
            }
        }
        else //第一个为谷值
        {
            minelem[1]=price[0];
            for(i=3;i<d;i+=2)
            {
                minelem[i]=price[i-1]<minelem[i-2]?price[i-1]:minelem[i-2];
            }
        }
        //对峰值，计算之前最小值时买进，当天卖出的收益
        //对谷值，计算当天买进，之后最大值时卖出的收益
        if(price[0]>price[1]){dp[0]=0;}
        else {dp[0]=maxelem[0]-price[0];}
        for(i=1;i<d;i++)
        {
            if(price[i]<price[i-1]) dp[i]=maxelem[i]-price[i];
            else dp[i]=price[i]-minelem[i];
        }

        //对峰值，计算之后谷值买入收益的最大值
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

        //遍历所有第一次卖出的峰值，取最大总收益
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
