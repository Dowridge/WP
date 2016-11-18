#include <iostream>
#include <iomanip>
using namespace std;

void display_array(int array[],int SIZE);
int fill_array(int array[],int SIZE);
int linear_search(int array[],int SIZE);
void sort(int array[],int SIZE);




int main()
{
const int SIZE=10;

int array[SIZE];

fill_array(array,SIZE);

cout<<"\nBelow is the content stored in each array cell.: "<<endl<<endl;

display_array(array,SIZE);

cout<<"\nBelow is the array sorted from least to greatest: "<<endl<<endl;

sort(array,SIZE);

linear_search(array,SIZE);

system("PAUSE");
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
    for(int i=0;i<SIZE;i++)
    {
	cout<<array[i]<<endl;
    }
}

void sort(int  array[],int SIZE)
{
bool swap;
int temp;

     do 
     { 
     swap = false; 
     for (int count = 0; count <(SIZE - 1); count++) 
     { 
     if (array[count] > array[count + 1]) 
        { 
        temp = array[count]; 
        array[count] = array[count + 1]; 
        array[count + 1] = temp; 
        swap = true; 
        } 
     } 
}    while (swap); 


     for (int i=0;i<10;i++)
     {
     cout<<array[i]<<endl;
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
