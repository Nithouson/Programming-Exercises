///拦截导弹 (POJ 2945)
/*
描述
某国为了防御敌国的导弹袭击，开发出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：
虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。
某天，雷达捕捉到敌国的导弹来袭，并观测到导弹依次飞来的高度，
请计算这套系统最多能拦截多少导弹。拦截来袭导弹时，必须按来袭导弹袭击的时间顺序，
不允许先拦截后面的导弹，再拦截前面的导弹。
输入
输入有两行，
第一行，输入雷达捕捉到的敌国导弹的数量k（k<=25），
第二行，输入k个正整数，表示k枚导弹的高度，按来袭导弹的袭击时间顺序给出，以空格分隔。
输出
输出只有一行，包含一个整数，表示最多能拦截多少枚导弹。
样例输入
8
300 207 155 300 299 170 158 65
样例输出
6
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int k,i,j;
    int height[25];
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>height[i];
    }
    int dp[k],maxm=1;
    dp[k-1]=1;
    for(i=k-2;i>=0;i--)
    {
        dp[i]=1;
        for(j=i+1;j<k;j++)
        {
            if(height[j]<=height[i]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
            }
        }
        //cout<<i<<" "<<dp[i]<<endl;
        if(dp[i]>maxm) maxm=dp[i];
    }
    cout<<maxm<<endl;
    return 0;
}
