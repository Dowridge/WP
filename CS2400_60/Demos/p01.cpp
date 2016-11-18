#include <iostream>
using namespace std;
int swap(int&, int&);

int main()
{
	int n1,n2;
cout<<"Enter two numbers to be swapped"<<endl;
cin>>n1>>n2;
cout<<"\nBefore swap"<<endl;
cout<<n1<<" "<<n2<<endl;
swap(n1,n2);
cout<<"\nAfter swap"<<endl;
cout<<n1<<" "<<n2<<endl;
}

int swap(int &x,int &y)
{
int temp;
temp=x;
x=y;
y=temp;	
	
}
