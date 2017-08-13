///�ļ��ṹͼ (POJ 2775)
/*����
�ڼ�����Ͽ����ļ�ϵͳ�Ľṹͨ�������á�Microsoft Windows�����"explorer"�������������һ�����ӡ�
��������ͼ�ν���֮ǰ��û��ͼ�λ��ı�ʾ�����ģ���ʱ����õķ�ʽ�ǰ�Ŀ¼���ļ��Ľṹ��ʾ��һ��"ͼ"�����ӣ�
����ʹ�����ŵ���ʽ����ʾĿ¼�Ľṹ�����磺
ROOT
|     dir1
|     file1
|     file2
|     file3
|     dir2
|     dir3
|     file1
file1
file2
���ͼ˵����ROOTĿ¼����������Ŀ¼�������ļ���
��һ����Ŀ¼����3���ļ����ڶ�����Ŀ¼�ǿյģ���������Ŀ¼����һ���ļ���

����
���������дһ�������ȡһЩ�������ݡ�ÿ��������ݱ�ʾһ����������ļ��ṹ��
ÿ�����������'*'��β�������к��������������'#'��β��
һ��������ݰ���һЩ�ļ���Ŀ¼�����֣���Ȼ������������û�и��������������ܼ���ROOTĿ¼��������Ŀ¼����
��������,��']'��ʾһ��Ŀ¼�����ݵĽ�����Ŀ¼���ֵĵ�һ����ĸ��'d'���ļ����ֵĵ�һ����ĸ��'f'��
�ļ�����������չ��Ҳ����û�У�����fmyfile.dat��fmyfile�����ļ���Ŀ¼�������ж��������ո�,���ȶ�������30��
һ��Ŀ¼�µ���Ŀ¼�������ļ�����֮�Ͳ�����30��
���
����ʾһ��Ŀ¼�����ݵ�ʱ������ʾ���е���Ŀ¼������еĻ�����Ȼ������ʾ�ļ�������еĻ�����
�ļ�Ҫ�������ֵ���ĸ���˳����ʾ��Ŀ¼���ð������ֵ���ĸ��˳����ʾ��ֻ��Ҫ����Ŀ¼���ֵ��Ⱥ���ʾ����
��ÿһ��������ݣ�����Ҫ�����"DATA SET x:"������x�ǲ������ݵı�ţ���1��ʼ����
�������������֮��Ҫ���һ��������������
����Ҫע����ǣ�����ʹ��һ��'|'��5���ո�����ʾ�����ŵĲ�Ρ�

��������
file1
file2
dir3
dir2
file1
file2
]
]
file4
dir1
]
file3
*
file2
file1
*
#

�������
DATA SET 1:
ROOT
|     dir3
|     |     dir2
|     |     file1
|     |     file2
|     dir1
file1
file2
file3
file4

DATA SET 2:
ROOT
file1
file2

��ʾ
һ��Ŀ¼��������Ŀ¼���ڲ�ͬ�Ĳ��
һ��Ŀ¼������������ļ�����ͬһ���
*/

#include <iostream>
#include <stack>
#include <set>
#include <string>
using namespace std;

int main()
{
    int dataset=1;
    string input;
    stack<string> filestack;
    int layers=-1;
    while(true)
    {
        cin>>input;
        if(input=="#") break;
        if(layers==-1)
        {
            cout<<"DATA SET "<<dataset<<":"<<endl;
            cout<<"ROOT"<<endl;
            layers=0;
        }
        if(input[0]=='f')
        {
            filestack.push(input);
        }
        else if(input[0]=='d')
        {
            layers++;
            for(int t=0;t<layers;t++)
            {
                cout<<"|     ";
            }
            cout<<input<<endl;
            filestack.push(input);
        }
        else if(input=="]")
        {
            set<string> fileset;
            while(filestack.top()[0]!='d')
            {
                fileset.insert(filestack.top());
                filestack.pop();
            }
            set<string>::iterator p;
            for(p=fileset.begin();p!=fileset.end();p++)
            {
                for(int t=0;t<layers;t++)
                {
                    cout<<"|     ";
                }
                cout<<*p<<endl;
            }
            layers--;
            filestack.pop();
        }
        else if(input=="*")
        {
            set<string> fileset;
            while(!filestack.empty())
            {
                fileset.insert(filestack.top());
                filestack.pop();
            }
            set<string>::iterator p;
            for(p=fileset.begin();p!=fileset.end();p++)
            {
                cout<<*p<<endl;
            }
            layers--;
            dataset++;
            cout<<endl;
        }
    }
    return 0;
}
