#include <iostream>
#include<string>
#include<stack>
#include <cstdlib>
#include<string.h>
#include <sstream>
using namespace std;
double count(string& a);
double icount(string& a,int j);
bool Isnum(char a);
double e1[20];//��������
char e2[20];//���������
double count(string& a)//���������ű��ʽ��ֵ
{
    int i,j=0,len=a.size(),m,n;
    string b;
    for(i=0;i<len;i++)
    {
        if(Isnum(a[i]))//�������벢�������
        {
            b+=a[i];
        }
        else
        {

            e1[j]=atof(b.c_str());//���ַ���ת���ɸ�����
            e2[j]=a[i];
            j++;
            b="";
        }
        if(i==len-1)
        {
             e1[j]=atof(b.c_str());
             j++;
        }
    }//e1����Ϊj,e2����Ϊj-1
    for(m=0;m<j-1;m++)//�������ȼ��ж������
    {
        if(e2[m]=='*')
        {
            e1[m]*=e1[m+1];
            for(n=m+1;n<j-1;n++)
        {
            e1[n]=e1[n+1];
        }
        for(n=m;n<j-2;n++)
        {
            e2[n]=e2[n+1];
        }
        }
        if(e2[m]=='/')
        {
            e1[m]/=e1[m+1];
            for(n=m+1;n<j-1;n++)//�����������λ
        {
            e1[n]=e1[n+1];
        }
        for(n=m;n<j-2;n++)
        {
            e2[n]=e2[n+1];
        }
        }


    }
     for(m=0;m<j-1;m++)
    {
        if(e2[m]=='+')
        {
            e1[m]+=e1[m+1];
            for(n=m+1;n<j-1;n++)
        {
            e1[n]=e1[n+1];
        }
        for(n=m;n<j-2;n++)
        {
            e2[n]=e2[n+1];
        }
        }
        if(e2[m]=='-')
        {
            e1[m]-=e1[m+1];
            for(n=m+1;n<j-1;n++)
        {
            e1[n]=e1[n+1];
        }
        for(n=m;n<j-2;n++)
        {
            e2[n]=e2[n+1];
        }
        }

    }
    return e1[0];
}
double icount(string& a,int j)//���������ű��ʽ��ֵ��ע��Ϊ������
{
    int m,n,len,term=0,i,d;
    string b[j];
    string c[j];
    do
    {
        len=a.size();
        //cout<<len<<endl;
        d=0;
    for(m=0;m<len;m++)
    {
        if(a[m]=='(')
           {
               d++;
               for(n=m+1;n<len;n++)
               {
                   if(a[n]=='('){break;}//�ж��Ƿ�Ϊ���ڲ�����
                   else if(a[n]==')')
                   {
                       //cout<<m<<endl<<n<<endl;
                       //exit(0);
                       for(i=m+1;i<n;i++)
                       {
                           b[term]+=a[i];
                       }
                       //cout<<b[term];
                       //exit(0);
                       stringstream ss;
                       ss << count(b[term]) << flush;//�Ѹ�����ת��Ϊ�ַ������滻
                       c[term]=ss.str();
                       //cout<<c[term];
                       //exit(0);
                       ss.clear();
                       a=a.replace(m,n-m+1,c[term]);//�滻
                       term++;
                       //cout<<a<<endl;
                       //exit(0);
                       break;
                   }
               }
           }
    }
    }while(d!=0);//�ж��Ƿ�������
    //exit(0);
    return count(a);

}
bool Isnum(char a)//�жϸ��ַ��Ƿ������ֵ�һ����
{
    int b=a;
    if(b>=48&&b<=57||b==46)
    {
        return true;
    }
    else return false;
}
int main()
{

    string equ;
    int len,i,j=0;
    char m;
    cout<<"-------------------------��ӭ�������׼�����---------------------"<<endl;
    do{
    cout<<"��������Ҫ����ı��ʽ��";
    cin>>equ;
    len=equ.size();
    for(i=0;i<len;i++)//�ж��Ƿ������Ž��з������
    {
        if(equ[i]=='(')
           {
               j++;
           }
    }
    //cout<<j;
    //exit(0);
    if(j==0)
    {
        cout<<count(equ)<<endl;;
    }
    else
    {
        cout<<icount(equ,j)<<endl;;
    }
    cout<<"����һ����������y���㣬����n�˳���"<<endl;//�Ƿ�����
    cin>>m;
    }while(m=='y');
}
