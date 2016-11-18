#include <iostream>
#include <iomanip>
using namespace std;

void display_array(int array[],int SIZE);
int fill_array(int array[],int SIZE);

int main()
{
const int SIZE=10;
int array[SIZE];

fill_array(array,SIZE);


display_array(array,SIZE);
system("Pause");
return 0;
}


int fill_array(int array[],int SIZE)
{
cout << "Enter 10 numbers: ";

for (int count = 0; count < SIZE; count++)
	{
	cout << "#" << (count + 1) << " ";
	cin >> array[count];
	}
}


void display_array(int array[],int SIZE)
{
cout<<"The numbers you entered are: "<<endl;

for(int i=0;i<=9;i++)
	{
	cout<<array[i]<<'\t';
	}
}

