///Courses (POJ 1469)
///Hungary Algorithm
/*描述
Consider a group of N students and P courses.
Each student visits zero, one or more than one courses.
Your task is to determine whether it is possible to form
a committee of exactly P students that satisfies simultaneously the conditions:
every student in the committee represents a different course
(a student can represent a course if he/she visits that course)
each course has a representative in the committee
输入
Your program should read sets of data from the std input.
The first line of the input contains the number of the data sets.
Each data set is presented in the following format:

P N
Count1 Student1 1 Student1 2 ... Student1 Count1
Count2 Student2 1 Student2 2 ... Student2 Count2
...
CountP StudentP 1 StudentP 2 ... StudentP CountP

The first line in each data set contains two positive integers separated by one blank:
P (1 <= P <= 100) - the number of courses and N (1 <= N <= 300) - the number of students.
The next P lines describe in sequence of the courses from course 1 to course P,
each line describing a course.
The description of course i is a line that starts with an integer Count i (0 <= Count i <= N)
representing the number of students visiting course i.
Next, after a blank, you'll find the Count i students, visiting the course,
each two consecutive separated by one blank.
Students are numbered with the positive integers from 1 to N.
There are no blank lines between consecutive sets of data. Input data are correct.
输出
The result of the program is on the standard output.
For each input data set the program prints on a single line "YES"
if it is possible to form a committee and "NO" otherwise.
There should not be any leading blanks at the start of the line.
样例输入
2
3 3
3 1 2 3
2 1 2
1 1
3 3
2 1 3
2 1 3
1 1
样例输出
YES
NO
*/


#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int P,N;
short g[101][301];
short matchC[101],matchS[301];
short visited[301];

bool Augmenting_Path(int i)
{
    int j;
    for(j=1;j<=N;j++)
    {
        if(g[i][j]==0) continue;
        if(visited[j]==1) continue;
        visited[j]=1;
        if(matchS[j]==0||Augmenting_Path(matchS[j]))
        {
            matchC[i]=j;
            matchS[j]=i;
            return true;
        }
        //visited[j]=0;
    }
    return false;
}


int main()
{
    int cases,i,j,stu,id;
    bool succ;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %d",&P,&N);
        succ=true;
        memset(g,0,sizeof(g));
        memset(matchC,0,sizeof(matchC));
        memset(matchS,0,sizeof(matchS));
        for(i=1;i<=P;i++)
        {
            scanf("%d",&stu);
            for(j=0;j<stu;j++)
            {
                scanf("%d",&id);
                g[i][id]=1;
            }
        }
        for(i=1;i<=P;i++)
        {
            memset(visited,0,sizeof(visited));
            if(!Augmenting_Path(i)){succ=false;break;}
        }
        if(succ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
