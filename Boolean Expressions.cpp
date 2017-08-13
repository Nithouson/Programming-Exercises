///Boolean Expressions (POJ 2106)
/*
描述
The objective of the program you are going to produce is to evaluate boolean expressions as the one
shown next:
Expression: ( V | V ) & F & ( F | V )
where V is for True, and F is for False. The expressions may include the following operators:
! for not , & for and, | for or , the use of parenthesis for operations grouping is also allowed.
To perform the evaluation of an expression, it will be considered the priority of the operators,
the not having the highest, and the or the lowest. The program must yield V or F ,
as the result for each expression in the input file.

输入
The expressions are of a variable length, although will never exceed 100 symbols.
Symbols may be separated by any number of spaces or no spaces at all, therefore,
the total length of an expression, as a number of characters, is unknown.
The number of expressions in the input file is variable and will never be greater than 20.
Each expression is presented in a new line, as shown below.

输出
For each test expression, print "Expression " followed by its sequence number, ": ",
and the resulting value of the corresponding test expression.
Separate the output for consecutive test expressions with a new line.
Use the same format as that shown in the sample output shown below.

样例输入
( V | V ) & F & ( F| V)
!V | V & V & !F & (F | V ) & (!F | F | !V & V)
(F&F|V|!V&!F&!(F|F&V))

样例输出
Expression 1: F
Expression 2: V
Expression 3: V
*/

#include <iostream>
#include <stack>
#include <map>
#include <cstdio>
using namespace std;

char Logic(char op,char v1,char v2=' ')
{
    bool a=(v1=='V'?true:false);
    bool b=(v2=='V'?true:false);
    switch(op)
    {
    case '!':
        return !a?'V':'F';
        break;
    case '&':

        return a&b?'V':'F';
        break;
    case '|':
        return a|b?'V':'F';
        break;
    }
}

int main()
{
    stack<char> value;
    stack<char> operators;
    map<char,int> prec;
    prec['!']=3;
    prec['|']=1;
    prec['&']=2;
    prec['(']=0;
    char input,op,v,v1,v2;
    int cases=1;
    while(scanf("%c",&input)!=EOF)
    {
        if(input==' ') continue;
        if(input=='V'||input=='F')
        {
            value.push(input);
        }
        else if(input=='!'||input=='|'||input=='&')
        {
            if(input=='!'&&(!operators.empty())&&operators.top()=='!')
                operators.pop();
            else
            {
                while(!operators.empty()&&!value.empty()&&prec[operators.top()]>=prec[input])
                {
                    op=operators.top();
                    operators.pop();
                    if(op=='!')
                    {
                        v=value.top();
                        value.pop();
                        value.push(Logic('!',v));
                    }
                    else
                    {
                        v2=value.top();
                        value.pop();
                        v1=value.top();
                        value.pop();
                        value.push(Logic(op,v1,v2));
                    }
                }
                operators.push(input);
            }
        }
        else if(input=='(')
        {
            operators.push(input);
        }
        else if(input==')')
        {
            op=operators.top();
            operators.pop();
            while(op!='(')
            {
                if(op=='!')
                {
                    v=value.top();
                    value.pop();
                    value.push(Logic('!',v));
                }
                else
                {
                    v2=value.top();
                    value.pop();
                    v1=value.top();
                    value.pop();
                    value.push(Logic(op,v1,v2));
                }
                op=operators.top();
                operators.pop();
            }
        }
        else if (input=='\n')
        {
            while(!operators.empty())
            {
                op=operators.top();
                operators.pop();
                if(op=='!')
                {
                    v=value.top();
                    value.pop();
                    value.push(Logic('!',v));
                }
                else
                {
                    v2=value.top();
                    value.pop();
                    v1=value.top();
                    value.pop();
                    value.push(Logic(op,v1,v2));
                }
            }
            cout<<"Expression "<<cases<<": "<<value.top()<<endl;
            value.pop();
            cases++;
        }
    }
    while(!operators.empty())
    {
        op=operators.top();
        operators.pop();
        if(op=='!')
        {
            v=value.top();
            value.pop();
            value.push(Logic('!',v));
        }
        else
        {
            v2=value.top();
            value.pop();
            v1=value.top();
            value.pop();
            value.push(Logic(op,v1,v2));
        }
    }
    cout<<"Expression "<<cases<<": "<<value.top()<<endl;
    return 0;
}
