///Zipper (POJ2192)
/*
描述
Given three strings, you are to determine whether the third string can be formed by
combining the characters in the first two strings. The first two strings can be mixed arbitrarily,
but each must stay in its original order.
For example, consider forming "tcraete" from "cat" and "tree":
String A: cat
String B: tree
String C: tcraete
As you can see, we can form the third string by alternating characters from the two strings.
As a second example, consider forming "catrtee" from "cat" and "tree":
String A: cat
String B: tree
String C: catrtee
Finally, notice that it is impossible to form "cttaree" from "cat" and "tree".
输入
The first line of input contains a single positive integer from 1 through 1000.
It represents the number of data sets to follow. The processing for each data set is identical.
The data sets appear on the following lines, one data set per line.
For each data set, the line of input consists of three strings, separated by a single space.
All strings are composed of upper and lower case letters only.
The length of the third string is always the sum of the lengths of the first two strings.
The first two strings will have lengths between 1 and 200 characters, inclusive.
输出
For each data set, print:
Data set n: yes
if the third string can be formed from the first two, or
Data set n: no
if it cannot. Of course n should be replaced by the data set number.
See the sample output below for an example.
样例输入
3
cat tree tcraete
cat tree catrtee
cat tree cttaree
样例输出
Data set 1: yes
Data set 2: yes
Data set 3: no
*/


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cache[201][201];

bool zip(string a,string b,string c,unsigned int apos,unsigned int bpos,unsigned int cpos)
{
    if (cache[apos][bpos]!=0)
    {
        return cache[apos][bpos]==1?true:false;
    }
    bool res;
    if(cpos==c.length()) {cache[apos][bpos]=1; return true;}
    if(apos==a.length())
    {
        if(b[bpos]!=c[cpos]) {cache[apos][bpos]=-1; return false;}
        else
        {
            res=zip(a,b,c,apos,bpos+1,cpos+1);
            cache[apos][bpos]=res?1:-1;
            return res;
        }
    }
    if(bpos==b.length())
    {
        if(a[apos]!=c[cpos]) {cache[apos][bpos]=-1; return false;}
        {
            res=zip(a,b,c,apos+1,bpos,cpos+1);
            cache[apos][bpos]=res?1:-1;
            return res;
        }
    }
    if(a[apos]!=c[cpos])
    {
        if(b[bpos]!=c[cpos]) {cache[apos][bpos]=-1; return false;}
        else
        {
            res=zip(a,b,c,apos,bpos+1,cpos+1);
            cache[apos][bpos]=res?1:-1;
            return res;
        }
    }
    else
    {
        if(b[bpos]!=c[cpos])
        {
            res=zip(a,b,c,apos+1,bpos,cpos+1);
            cache[apos][bpos]=res?1:-1;
            return res;
        }
        else
        {
            res=zip(a,b,c,apos,bpos+1,cpos+1)||zip(a,b,c,apos+1,bpos,cpos+1);
            cache[apos][bpos]=res?1:-1;
            return res;
        }
    }
}

int main()
{
    int N,i;
    string a,b,c;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        memset(cache,0,sizeof(cache));
        cin>>a>>b>>c;
        cout<<"Data set "<<i<<": ";
        if(zip(a,b,c,0,0,0))
            cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
