///分形盒 (OJ 10714)
/*
描述
分形，通常被定义为一个粗糙或零碎的几何形状，可以分成数个部分，且每一部分都（至少近似地）是整体缩小后的形状，
即具有自相似的性质。它跟分数维、自组织、非线性系统和混沌等具有非常重要的联系。
分形盒就是这样一种分形，它的定义如下：
维度是1的分形盒：

X

维度是2的分形盒：

X  X

  X

X  X

如果已知维度是(n-1)的分形盒，那么维度是n的分形盒的递归定义如下所示：

Box(n-1)               Box(n-1)

              Box(n-1)

Box(n-1)               Box(n-1)

你的任务是画一个维度为n的分形盒。

输入
输入包含多组测试数据。每一行包含一个正整数n表示分形盒的维度，n不大于7；最后一行是一个-1，表示输入结束。
输出
对于每组测试数据，输出要求维度的分形盒，注意X为大写字母。每组测试数据之后包含一行，改行只包含一个破折号。
样例输入
1
2
3
4
-1
样例输出
X
-
X X
 X
X X
-
X X   X X
 X     X
X X   X X
   X X
    X
   X X
X X   X X
 X     X
X X   X X
-
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
         X X   X X
          X     X
         X X   X X
            X X
             X
            X X
         X X   X X
          X     X
         X X   X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
-
*/


#include <iostream>
#include <string>
using namespace std;
int graphsize[8]={0,1,3,9,27,81,243,729};
string* mem[8];

string addspace(string a,int n)
{
    for(int i=0;i<n;i++)
    {
        a+=" ";
    }
    return a;
}

void draw(int level)
{
    if(level==1) {mem[1]=new string[1]; mem[1][0]="X"; return;}
    int cursize=graphsize[level],line;
    mem[level]=new string[cursize];
    for(line=0;line<cursize/3;line++)
    {
        mem[level][line]=mem[level-1][line];
        mem[level][line]=addspace(mem[level][line],cursize/3);
        mem[level][line]+=mem[level-1][line];
    }
    for(line=cursize/3;line<2*cursize/3;line++)
    {
        mem[level][line]="";
        mem[level][line]=addspace(mem[level][line],cursize/3);
        mem[level][line]+=mem[level-1][line-cursize/3];
        mem[level][line]=addspace(mem[level][line],cursize/3);
    }
    for(line=2*cursize/3;line<cursize;line++)
    {
        mem[level][line]=mem[level-1][line-2*cursize/3];
        mem[level][line]=addspace(mem[level][line],cursize/3);
        mem[level][line]+=mem[level-1][line-2*cursize/3];
    }
    return;
}

void output(int level)
{
    for(int l=1;l<=level;l++)
    {
        draw(l);
    }
    for(int i=0;i<graphsize[level];i++)
    {
        cout<<mem[level][i]<<endl;
    }
}

int main()
{
    int level;
    while(cin>>level)
    {
        if(level==-1) break;
        else
        {
            output(level);
            cout<<"-"<<endl;
        }
    }
    return 0;
}
