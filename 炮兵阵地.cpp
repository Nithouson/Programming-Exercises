///�ڱ���� (POJ 1185)
/*
����
˾��Ľ����Ǵ�����N*M�������ͼ�ϲ������ǵ��ڱ����ӡ�
һ��N*M�ĵ�ͼ��N��M����ɣ���ͼ��ÿһ�������ɽ�أ���"H" ��ʾ����Ҳ������ƽԭ����"P"��ʾ��������ͼ��
��ÿһ��ƽԭ�����������Բ���һ֧�ڱ����ӣ�ɽ���ϲ��ܹ������ڱ����ӣ���
һ֧�ڱ������ڵ�ͼ�ϵĹ�����Χ��ͼ�к�ɫ������ʾ��
����ڵ�ͼ�еĻ�ɫ����ʶ��ƽԭ�ϲ���һ֧�ڱ����ӣ���ͼ�еĺ�ɫ�������ʾ���ܹ�������������
�غ������Ҹ��������������¸�����ͼ��������ɫ���������������
��ͼ�Ͽɼ��ڱ��Ĺ�����Χ���ܵ��ε�Ӱ�졣
���ڣ������ǹ滮��β����ڱ����ӣ��ڷ�ֹ���˵�ǰ���£���֤�κ���֧�ڱ�����֮�䲻�ܻ��๥����
���κ�һ֧�ڱ����Ӷ���������֧�ڱ����ӵĹ�����Χ�ڣ�����������ͼ����������ܹ��ڷŶ����Ҿ����ڱ����ӡ�
����
��һ�а��������ɿո�ָ�����������ֱ��ʾN��M��
��������N�У�ÿһ�к���������M���ַ�('P'����'H')���м�û�пո񡣰�˳���ʾ��ͼ��ÿһ�е����ݡ�N <= 100��M <= 10��
���
��һ�У�����һ������K����ʾ����ܰڷŵ��ڱ����ӵ�������
��������
5 4
PHPP
PPHH
PPPP
PHPP
PHHP
�������
6
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;///n rows,m columns
int atlas[100];
int num=0,curstate[10];
int maxcannon;
int dp[100][100][100];

struct row
{
    int state,cannon;
}rowstate[100];

void CalStates(int pos)
{
    if(pos==m)
    {
        int cannonnum=0;
        for(int c=0;c<m;c++)
        {
            rowstate[num].state+=curstate[c];
            cannonnum+=curstate[c];
            if(c!=m-1) rowstate[num].state<<=1;
        }
        rowstate[num].cannon=cannonnum;
        num++;
        return;
    }
    curstate[pos]=1;
    if(pos+3<=m-1) CalStates(pos+3);
    else CalStates(m);
    curstate[pos]=0;
    CalStates(pos+1);
    return;
}

int main()
{
    cin>>n>>m;
    char input;
    for(int r=0;r<n;r++)
    {
        atlas[r]=0;
        for(int c=0;c<m;c++)
        {
            cin>>input;
            atlas[r]+=input=='H'?1:0;
            if(c!=m-1) atlas[r]<<=1;
        }
    }
    memset(curstate,0,sizeof(curstate));
    memset(dp,-1,sizeof(dp));
    CalStates(0);
    maxcannon=0;
    for(int s=0;s<num;s++)
    {
         if(rowstate[s].state&atlas[0]) continue;
         dp[0][s][0]=rowstate[s].cannon;
         if(n==1) maxcannon=max(maxcannon,dp[0][s][0]);
    }
    for(int r=1;r<n;r++)
    {
        for(int scur=0;scur<num;scur++)
        {
            if(rowstate[scur].state&atlas[r]) continue;
            for(int sprev=0;sprev<num;sprev++)
            {
                if(rowstate[sprev].state&atlas[r-1]) continue;
                if(rowstate[scur].state&rowstate[sprev].state)continue;
                if(r==1) {dp[1][scur][sprev]=dp[0][sprev][0]+rowstate[scur].cannon;}
                else
                {
                    dp[r][scur][sprev]=0;
                    for(int spprev=0;spprev<num;spprev++)
                    {
                        if(rowstate[spprev].state&atlas[r-2]) continue;
                        if(rowstate[scur].state&rowstate[spprev].state)continue;
                        if(rowstate[sprev].state&rowstate[spprev].state)continue;
                        dp[r][scur][sprev]=max(dp[r][scur][sprev],dp[r-1][sprev][spprev]+rowstate[scur].cannon);
                    }
                }
                if(r==n-1)maxcannon=max(maxcannon,dp[n-1][scur][sprev]);
            }
        }
    }
    cout<<maxcannon<<endl;
    return 0;
}
