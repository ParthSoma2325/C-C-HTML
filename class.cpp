#include<iostream>

using namespace std;
class hmm
{
public : float r, area ;
void takedata();
};
void hmm :: takedata()
{
cout<<"Enter radius of circle = ";
cin>>r;
area = 3.14 * r * r ;
cout<<"Area of circle is ="<<area;

}
int main() 
{
hmm obj1;
obj1.  takedata();


}