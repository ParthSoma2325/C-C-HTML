#include<iostream>
#include<conio.h>
using namespace std;

int main()
{


int a,b,c,d,e;
char oper;
float f;

cout<<"Enter the first no.:\n";
cin>>a;

cout<<"Enter the operator:\n";
cin>>oper;

cout<<"Enter the second no.:\n";
cin>>b;

if(oper=='+')
{
c = a+b;
cout<<"\n The result is: "<<c;
}
else if(oper=='-')
{
    d = a-b;
    cout<<"\n The result is: "<<d;
    
}

else if (oper== '/')
{
if(b==0)
{
    cout<<"Denominator should not be zero";
}
else
{
f = (float)a/b;

cout<<"\nThe result is:"<<f;
}
}

else if(oper == '*')
{
e = a*b;
cout<<"The result is:\n"<<e;

}



}

