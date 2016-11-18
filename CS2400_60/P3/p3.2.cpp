//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P3.2
//Date assigned: 2/26/16
//     Due date: 3/8/16
//       Remark: This program finds the location of a key using binary and linear search, dynamically.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>

int fillArray(int *a, int n);
// Pre: fills the array with user input based on
//Post: returns an array 

void displayArray(int *a, int n);
// Pre:  This function reads the numbers stored in each cell.
//Post: Displays the data in each dynamic array cell.

void selectSort(int *a, int n);
// Pre: takes in the array and its size.
//Post: sorts the array contents based on least to greatest

int linear_search(int *a, int n, int key);
// Pre: is passed the value to be found in the array.
//Post: returns -1 or nothing based on if the number is found.

int binary_search(int *a, int n, int key, int first, int last);
// Pre: is passed the array, array size, key, first array location and last.
//Post: returns -1 or nothing based on if the number is found

using namespace std;
int main()
{
	int n, *a, key, binary, linear;

	cout << "Enter the number of students: " ;
	cin >> n;
	
	a = new int [n];
	assert(a != 0);
	fillArray(a, n);
	
	displayArray(a, n);
	cout << "\nKeys for Linear and Binary Searches: ";
	cin >> key;
	
 linear = linear_search(a, n, key);

if (linear == -1)
	cout << "Linear Seach: Not found!" << endl;
	else
	cout << "Linear Seach: Key value " << key << " found in score[" << linear << "]" << endl;
	
	binary = binary_search(a, n, key, 0, n);
	
	if (binary >= 0)
		cout << "Binary Seach: Key value " << key << " found in score[" << binary << "]." << endl;
	else
		cout << "Binary Seach: Key value " << key << " Not found!" << endl;
		
 	delete [] a;
system("PAUSE");
return 0;
}


void displayArray(int *a, int n)
{
	cout << "Listing of student scores:" << endl;
 	for(int c = 0; c < n; c++)
 	{
		cout << a[c] << '\t';	
 	} 
	cout << endl;  
}

int fillArray(int *a, int n)
{
	int temp;
	cout << "Fill the array below: " << endl;
 	for(int c = 0; c < n; c++)
 	{
 	  cin >> temp;
 	  if(temp >= 0 && temp <= 100)
			 *(a+c) = temp;
 	  else
  	cout<<"Please relaunch the program and enter scores between the ranges 0-100: "<<endl;	

}
}
int linear_search(int *a, int n, int key)
{
	for(int i = 0; i < n; i++)
	{
		if(key == a[i])
			return i;
	}
	return -1;	
} 

int binary_search(int *a, int n, int key, int first, int last)
{
	int middle;
	
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (key == a[middle])
			return middle;
		else if (key > a[middle])
			first = middle + 1;
		else
			last = middle - 1;
	}
	return -1;
}

