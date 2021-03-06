///Blocks (POJ 1390)
/*
����
Some of you may have played a game called 'Blocks'. There are n blocks in a row, each box has a color.
Here is an example: Gold, Silver, Silver, Silver, Silver, Bronze, Bronze, Bronze, Gold.
If some adjacent boxes are all of the same color, and both the box to its left(if it exists) and
its right(if it exists) are of some other color, we call it a 'box segment'. There are 4 box segments.
That is: gold, silver, bronze, gold. There are 1, 4, 3, 1 box(es) in the segments respectively.
Every time, you can click a box, then the whole segment containing that box DISAPPEARS.
If that segment is composed of k boxes, you will get k*k points.
for example, if you click on a silver box, the silver segment disappears, you got 4*4=16 points.
Find the highest score you can get, given an initial state of this game.
����
The first line contains the number of tests t(1<=t<=15). Each case contains two lines.
The first line contains an integer n(1<=n<=200), the number of boxes.
The second line contains n integers, representing the colors of each box. The integers are in the range 1~n.
���
For each test case, print the case number and the highest possible score.
��������
2
9
1 2 2 2 2 3 3 3 1
1
1
�������
Case 1: 29
Case 2: 1
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct section
{
    int color;
    int num;
}range[200];
int cache[200][200][200];

int Blocks(int st,int ed,int tomerge)
{
    if(cache[st][ed][tomerge]) return cache[st][ed][tomerge];
    if(st==ed) return (range[st].num+tomerge)*(range[st].num+tomerge);
    int score=0,temp;
    score=(range[ed].num+tomerge)*(range[ed].num+tomerge)+Blocks(st,ed-1,0);
    for(int pos=ed-2;pos>=st;pos--)
    {
        if(range[ed].color==range[pos].color)
        {
            temp=Blocks(pos+1,ed-1,0)+Blocks(st,pos,tomerge+range[ed].num);
            score=score<temp?temp:score;
        }
    }
    cache[st][ed][tomerge]=score;
    return score;
}


int main()
{
    int N,i,T,input,curcolor,curnum,sect;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        memset(cache,0,sizeof(cache));
        cin>>T;
        T--;
        cin>>curcolor;
        curnum=1;
        sect=0;
        while(T--)
        {
            cin>>input;
            if(input==curcolor) curnum++;
            else
            {
                range[sect].color=curcolor;
                range[sect].num=curnum;
                curcolor=input;
                curnum=1;
                sect++;
            }
        }
        range[sect].color=curcolor;
        range[sect].num=curnum;
        cout<<"Case "<<i<<": "<<Blocks(0,sect,0)<<endl;
    }
    return 0;
}
