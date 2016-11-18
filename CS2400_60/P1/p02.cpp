#include <iostream>
using namespace std;
void largest_and_Smallest (int,int,int,int,int&,int&);

int main()
{

int n1,n2,n3,n4,large,small;
cout<<"Enter four numbers so the smallest and largerst values may be returned:";
cin>>n1>>n2>>n3>>n4;

largest_and_Smallest(n1,n2,n3,n4,large, small);
cout<<"Largest: "<<large<<endl;
cout<<"Smallest: "<<small<<endl;
}



void largest_and_Smallest (int w,int x, int y, int z, int& large, int& small)
{
large=w;
small=w;

if(x>large)
large=x;

if(y>large)
large=y;

if(z>large)
large=z;

if(x<small)
small=x;

if(y<small)
small=y;

if(z<small)
small=z;	
}
