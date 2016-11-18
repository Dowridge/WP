#include <iostream>
#include <iomanip>
using namespace std;
int reverse_array(int array[],int SIZE);
void display_array(int array[],int SIZE);
int fill_array(int array[],int SIZE);
int linear_search(int array[],int SIZE);

int main()
{
const int SIZE=10;
int array[SIZE];
fill_array(array,SIZE);
cout<<"\nbefore reverse"<<endl;
display_array(array,SIZE);
reverse_array(array,SIZE);
cout<<"\nafter reverse"<<endl;
display_array(array,SIZE);
linear_search(array,SIZE);
system("Pause");
return 0;
}

int fill_array(int array[],int SIZE)
{
cout << "Enter 10 numbers: "<<endl;

for (int count = 0; count < SIZE; count++)
	{
	cout << "#" << (count + 1) << " ";
	cin >> array[count];
	}
}


void display_array(int array[],int SIZE)
{

for(int i=0;i<=9;i++)
	{
	cout<<array[i]<<'\t';
	}
}

int reverse_array(int array[],int SIZE)
{
int temp;


for(int i=0,j=9;i<=j;i++,j--)
	{
	temp=array[i];
	array[i]=array[j];
	array[j]=temp;	
	}

}

int linear_search(int array[],int SIZE)	
{
int search;
cout<<"\nEnter a number and ill tell you if its in the array"<<endl;
cin>>search;

for(int i=0;i<9;i++)
	{
	if(search==array[i])
	{
	cout<<"\nYes this number is in the array in "<< i <<endl;	
	break;
	}
	}	
}
	


