///���κ� (OJ 10714)
/*
����
���Σ�ͨ��������Ϊһ���ֲڻ�����ļ�����״�����Էֳ��������֣���ÿһ���ֶ������ٽ��Ƶأ���������С�����״��
�����������Ƶ����ʡ���������ά������֯��������ϵͳ�ͻ���Ⱦ��зǳ���Ҫ����ϵ��
���κо�������һ�ַ��Σ����Ķ������£�
ά����1�ķ��κУ�

X

ά����2�ķ��κУ�

X  X

  X

X  X

�����֪ά����(n-1)�ķ��κУ���ôά����n�ķ��κеĵݹ鶨��������ʾ��

Box(n-1)               Box(n-1)

              Box(n-1)

Box(n-1)               Box(n-1)

��������ǻ�һ��ά��Ϊn�ķ��κС�

����
�����������������ݡ�ÿһ�а���һ��������n��ʾ���κе�ά�ȣ�n������7�����һ����һ��-1����ʾ���������
���
����ÿ��������ݣ����Ҫ��ά�ȵķ��κУ�ע��XΪ��д��ĸ��ÿ���������֮�����һ�У�����ֻ����һ�����ۺš�
��������
1
2
3
4
-1
�������
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
