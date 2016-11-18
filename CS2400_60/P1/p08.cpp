#include <iostream>
#include <iomanip>
using namespace std;
void display_array(int array[],int SIZE);
int fill_array(int array[],int SIZE);
int linear_search(int array[],int SIZE);

int main()
{
const int SIZE=10;
int array[SIZE];
fill_array(array,SIZE);
cout<<"\nBelow is the content stored in each array cell: "<<endl<<endl;
display_array(array,SIZE);
cout<<"\nBelow is the linear seach: "<<endl<<endl;
linear_search(array,SIZE);
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

int linear_search(int array[],int SIZE)	
{
int search;
cout<<"Enter a number and ill tell you if its in the array: ";
cin>>search;

for(int i=0;i<9;i++)
	{
		if(search==array[i])
		{
		cout<<"\nYes this number is in the array, in cell "<< i <<endl;	
	
		}
		else
		cout<<"\nThis number does not exist in the array"<<endl;
		return -1;
	}
}
	
