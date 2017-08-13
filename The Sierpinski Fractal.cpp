///The Sierpinski Fractal(POJ 1941)
/*
����
Consider a regular triangular area, divide it into four equal triangles of half height and remove the one in the middle.
Apply the same operation recursively to each of the three remaining triangles.
If we repeated this procedure infinite times, we'd obtain something with an area of zero.
The fractal that evolves this way is called the Sierpinski Triangle.
Although its topological dimension is 2, its Hausdorff-Besicovitch dimension is log(3)/log(2)~1.58,
a fractional value (that's why it is called a fractal).
By the way, the Hausdorff-Besicovitch dimension of the Norwegian coast is approximately 1.52,
its topological dimension being 1.

For this problem, you are to outline the Sierpinski Triangle up to a certain recursion depth,
using just ASCII characters. Since the drawing resolution is thus fixed, you'll need to grow the picture appropriately.
Draw the smallest triangle (that is not divided any further) with two slashes, to backslashes and two underscores like this:
 /\
/__\
To see how to draw larger triangles, take a look at the sample output.

����
The input contains several testcases. Each is specified by an integer n. Input is terminated by n=0.
Otherwise 1<=n<=10 indicates the recursion depth.
���
For each test case draw an outline of the Sierpinski Triangle with a side's total length of 2n characters.
Align your output to the left, that is, print the bottom leftmost slash into the first column.
The output must not contain any trailing blanks. Print an empty line after each test case.
��������
3
2
1
0
�������
       /\
      /__\
     /\  /\
    /__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\

   /\
  /__\
 /\  /\
/__\/__\

 /\
/__\
*/

#include <iostream>
#include <string>
using namespace std;
string elem[2]={" /\\","/__\\"};

string setspace(string& arg,int space)
{
    for(int u=1;u<=space;u++)
    {
        arg=" "+arg;
    }
    return arg;
}

string* Sierpinski(int n,int space,int output=0)
{
    string* out=new string [1<<n];
    if(n==1)
    {
        out[0]=out[1]="";
        for(int u=1;u<=space;u++)
        {
            out[0]+=" ";
            out[1]+=" ";
        }
        out[0]+=elem[0];
        out[1]+=elem[1];
    }
    else
    {
        int line;
        string* seg=Sierpinski(n-1,0);
        for(line=0;line<(1<<(n-1));line++)
        {
            out[line]="";
            out[line]=setspace(out[line],1<<(n-1));
            out[line]+=seg[line];
        }
        for(line=1<<(n-1);line<(1<<(n));line++)
        {
            out[line]=seg[line-(1<<(n-1))];
            out[line]=setspace(out[line],(1<<n)-1-line);
            out[line]=seg[line-(1<<(n-1))]+out[line];
        }
    }
    if(output)
    {
        for(int line=0;line<(1<<n);line++)
        {
            cout<<out[line]<<endl;
        }
    }
    return out;
}

int main()
{
    int depth;
    while(1)
    {
        cin>>depth;
        if(depth==0) break;
        else Sierpinski(depth,0,1);
        cout<<endl;
    }
    return 0;
}
