//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P2.2
//Date assigned: 2/13/16
//     Due date: 2/23/16
//       Remark: This program sorts, preforms a binary and linear search on a list of scores.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int fillArray(int score[], int size);
// Pre: takes in the size of the array.
//Post: returns the partially filled value of the array.

void displayArray(int score[], int n);
// Pre:  This function reads the numbers stored in each cell.
//Post: Displays the data in each array cell.

void selectSort(int arr[], int n);
// Pre: reads the array contents and its partially filled size.
//Post: sorts the array elements from least 

int linear_search(int score[], int n, int key);
// Pre: is passed a key from the uses that is a number to be determined if it lies in the array.
//Post: uses the linear search algorithm to find the location of an element in the array by returning its location

int binary_search(int a[], int n, int key, int first, int last);
// Pre: is passed the array, the partially filled size, the first cell and the last cell of the array
//Post: uses the binary search algorithm to find the location of an element in the array by returning its location

int main()
{
	const int SIZE = 10;
	int score[SIZE], n, key, linear,binary;
	n = fillArray(score, SIZE);
	
	cout << "\nBefore Sorting: ";
	displayArray(score, n);
	
	selectSort(score, n);
	
	cout << "\nAfter Sorting:";
	displayArray(score, n);
	
	cout << "\nKeys for Linear and Binary Searches: ";
	cin >> key;
	
	linear=linear_search(score,n,key);
	
	cout<<endl;
	if (linear == -1)
	cout << "Linear Seach: Not found!" << endl;
	else
	cout << "Linear Seach: Key value " << key << " found in score[" << linear << "]" << endl;
		
	binary=binary_search(score,n,key,0,n);
	if (binary >= 0)
		cout << "Binary Seach: Key value " << key << " found in score[" << binary << "]." << endl;
	else
		cout << "Binary Seach: Key value " << key << " Not found!" << endl;


cout<<endl;
system("PAUSE");
return 0;
}

int fillArray(int score[],int SIZE)
{
	int i = 0;
	int num;
	cout << "Enter up to " << SIZE << " scores, -99 to end the list."<<endl;
	
	do
	{
		cout << "Enter a number: ";
		cin >> num;
		
	        if(num == -99)
            {
            break;
            }	
		score[i] = num;
		i++;

		if (i == SIZE)
		{
			cout << "The array is full; no more  value can be stored!" << endl;
			num = -99;
		}	
	} while (num != -99);
	return i;
}

void displayArray(int score[], int n)
{
 	 cout << endl;
   		for(int i = 0; i < n; i++)
   		{
   		cout << score[i] <<'\t';
		}  
	cout << endl;    
}

void selectSort(int score[], int n)
{
	int pos_min,temp;

	for (int i=0; i < n-1; i++)
	{
	    pos_min = i;
		
		for (int j=i+1; j < n; j++)
		{
		if (score[j] < score[pos_min])
                   pos_min=j;
		}
            if (pos_min != i)
            {
                 temp = score[i];
                 score[i] = score[pos_min];
                 score[pos_min] = temp;
            }
	}
}

int linear_search(int score[], int n, int key)
{
	for(int i = 0; i < n; i++)
	{
		if(key == score[i])
			return i;
	}
	return -1;	
} 

int binary_search(int a[], int n, int key, int first, int last)
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
