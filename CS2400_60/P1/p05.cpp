#include <iostream>
#include <iomanip>
using namespace std;

void display_array(int array[],int SIZE);


int main()
{
const int SIZE=10;
int array[SIZE]={10,11,22,33,44,66,77,88,99,546};
display_array(array,SIZE);

system("Pause");
return 0;
}

void display_array(int array[],int SIZE)
{

for(int i=0;i<SIZE;i++)
	{
	cout<<array[i]<<'\t';
	}
}

