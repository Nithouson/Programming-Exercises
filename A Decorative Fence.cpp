///A Decorative Fence (POJ 1037)
/*
描述
Richard just finished building his new house. Now the only thing the house misses is a cute little wooden fence.
He had no idea how to make a wooden fence, so he decided to order one.
Somehow he got his hands on the ACME Fence Catalog 2002, the ultimate resource on cute little wooden fences.
After reading its preface he already knew, what makes a little wooden fence cute.
A wooden fence consists of N wooden planks, placed vertically in a row next to each other.
A fence looks cute if and only if the following conditions are met:
The planks have different lengths, namely 1, 2, . . . , N plank length units.
Each plank with two neighbors is either larger than each of its neighbors or smaller than each of them.
(Note that this makes the top of the fence alternately rise and fall.)
It follows, that we may uniquely describe each cute fence with N planks as a permutation a1, . . . , aN of
the numbers 1, . . . ,N such that (any i; 1 < i < N) (ai − ai−1)*(ai − ai+1) > 0 and vice versa,
each such permutation describes a cute fence.
It is obvious, that there are many different cute wooden fences made of N planks.
To bring some order into their catalog, the sales manager of ACME decided to order them in the following way:
Fence A (represented by the permutation a1, . . . , aN) is in the catalog before fence B (represented by b1, . . . , bN)
if and only if there exists such i, that (any j < i) aj = bj and (ai < bi).
(Also to decide, which of the two fences is earlier in the catalog, take their corresponding permutations,
find the first place on which they differ and compare the values on this place.)
All the cute fences with N planks are numbered (starting from 1) in the order they appear in the catalog.
This number is called their catalog number.
After carefully examining all the cute little wooden fences, Richard decided to order some of them.
For each of them he noted the number of its planks and its catalog number.
Later, as he met his friends, he wanted to show them the fences he ordered, but he lost the catalog somewhere.
The only thing he has got are his notes. Please help him find out, how will his fences look like.
输入
The first line of the input file contains the number K (1 <= K <= 100) of input data sets.
K lines follow, each of them describes one input data set.
Each of the following K lines contains two integers N and C (1 <= N <= 20), separated by a space.
N is the number of planks in the fence, C is the catalog number of the fence.
You may assume, that the total number of cute little wooden fences with 20 planks fits into a 64-bit signed integer variable
(long long in C/C++, int64 in FreePascal).
You may also assume that the input is correct, in particular that C is at least 1 and it doesn't exceed the number of
cute fences with N planks.
输出
For each input data set output one line, describing the C-th fence with N planks in the catalog.
More precisely, if the fence is described by the permutation a1, . . . , aN, then the corresponding line of the output file
should contain the numbers ai (in the correct order), separated by single spaces.
样例输入
2
2 1
3 3
样例输出
1 2
2 3 1
*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int up[21][21],down[21][21];

int main()
{
    int n,head,i;
    up[2][1]=down[2][2]=1;
    up[2][2]=down[2][1]=0;
    for(n=3;n<=20;n++)
    {
        for(head=1;head<=n;head++)
        {
            up[n][head]=0;
            down[n][head]=0;
            for(i=head;i<=n-1;i++)
            {
                up[n][head]+=down[n-1][i];
            }
            for(i=1;i<head;i++)
            {
                down[n][head]+=up[n-1][i];
            }
        }
    }
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        long long int C;
        bool outputflag=false;
        cin>>N>>C;
        vector<int> left;
        for(int l=1;l<=N;l++)
        {
            left.push_back(l);
        }
        int h0=1;
        bool doup=true,dodown=true;
        for(int d=N;d>1;d--)
        {
            for(int h=h0;h<=N;h++)
            {
                if(dodown)
                {
                    if(C-down[d][h]>0) C-=down[d][h];
                    else
                    {
                        if(outputflag) cout<<" "<<left[h-1];
                        else {cout<<left[h-1]; outputflag=true;}
                        left.erase(left.begin()+h-1);
                        dodown=false;
                        doup=true;
                        h0=1;
                        break;
                    }
                }
                if(doup)
                {
                    if(C-up[d][h]>0) C-=up[d][h];
                    else
                    {
                        if(outputflag) cout<<" "<<left[h-1];
                        else {cout<<left[h-1]; outputflag=true;}
                        left.erase(left.begin()+h-1);
                        doup=false;
                        dodown=true;
                        h0=h;
                        break;
                    }
                }
            }
        }
        if(outputflag) cout<<" "<<left[0];
        else cout<<left[0];
        cout<<endl;
    }
    return 0;
}
