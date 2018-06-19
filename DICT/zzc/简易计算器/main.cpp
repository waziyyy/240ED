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
double e1[20];//储存数字
char e2[20];//储存运算符
double count(string& a)//计算无括号表达式的值
{
    int i,j=0,len=a.size(),m,n;
    string b;
    for(i=0;i<len;i++)
    {
        if(Isnum(a[i]))//把数分离并存进数组
        {
            b+=a[i];
        }
        else
        {

            e1[j]=atof(b.c_str());//把字符串转换成浮点数
            e2[j]=a[i];
            j++;
            b="";
        }
        if(i==len-1)
        {
             e1[j]=atof(b.c_str());
             j++;
        }
    }//e1长度为j,e2长度为j-1
    for(m=0;m<j-1;m++)//根据优先级判断运算符
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
            for(n=m+1;n<j-1;n++)//进行数组的移位
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
double icount(string& a,int j)//计算有括号表达式的值，注释为测试用
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
                   if(a[n]=='('){break;}//判断是否为最内侧括号
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
                       ss << count(b[term]) << flush;//把浮点数转换为字符串并替换
                       c[term]=ss.str();
                       //cout<<c[term];
                       //exit(0);
                       ss.clear();
                       a=a.replace(m,n-m+1,c[term]);//替换
                       term++;
                       //cout<<a<<endl;
                       //exit(0);
                       break;
                   }
               }
           }
    }
    }while(d!=0);//判断是否还有括号
    //exit(0);
    return count(a);

}
bool Isnum(char a)//判断该字符是否是数字的一部分
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
    cout<<"-------------------------欢迎来到简易计算器---------------------"<<endl;
    do{
    cout<<"请输入需要计算的表达式：";
    cin>>equ;
    len=equ.size();
    for(i=0;i<len;i++)//判断是否有括号进行分类计算
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
    cout<<"再算一个？（输入y再算，输入n退出）"<<endl;//是否再算
    cin>>m;
    }while(m=='y');
}
