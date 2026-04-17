#include<iostream>
#include<conio.h>
using namespace std;


void passbyref(int &a)
{

a = a + 1;  

}
int main ()
{

int a = 4;
int &b = a;

 passbyref(b);

 cout<<"a is:"<<a<<"\n";

}

