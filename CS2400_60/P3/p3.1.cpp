//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P3.1
//Date assigned: 2/26/16
//     Due date: 3/8/16
//       Remark: This program uses dynamic arrays to computer the average and the standard deivation
// 			     for a list of student scores

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>

void fillArray(int *a, int n);
// Pre: fills the array with user input based on
//Post: returns an array 

double computeAvg(int *a, int n);
// Pre: takes in the dynamic array 
//Post: returns the standard deviation of all the array variables

double computerStandardDeviation(int *a, int n, double avg);
// Pre: is passed the array and their contents and their average.
//Post: returns the standard deviation

void displayArray(int *a, int n);
// Pre:  This function reads the numbers stored in each cell.
//Post: Displays the data in each dynamic array cell.

using namespace std;

int main()
{
	int n, *a;
	double avg, standard;	
	cout << "Enter the number of students: " ;
	cin >> n;
	
	a = new int [n];
	assert(a != 0);
	
	fillArray(a, n);
	displayArray(a, n);
	avg = computeAvg(a, n);
	standard = computerStandardDeviation(a, n, avg);
	
	cout << "\nTotal # of Students: " << n << endl;
	cout << fixed << setprecision(2);
	cout << setw(21) << "Class Average: "<< avg << endl;
	cout << setw(21) << "Standard Deviation: " << standard;
 	cout << endl;
 	
 	delete [] a;
system("PAUSE");
return 0;
}


void displayArray(int *a, int n)
{
	cout << "\nListing of student scores:" << endl;
 	for(int c = 0; c < n; c++)
 	{
		cout << a[c] << '\t';	
 	} 
	cout << endl;  
}

void fillArray(int *a, int n)
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

double computeAvg(int *a, int n)
{
 	double counter = 0;
	for(int i = 0;i < n; i++)
	counter += a[i];
	return counter / n;
	
}

double computerStandardDeviation(int *a, int n, double avg)
{
 	   double devi, squared = 0, strd, k;
	   int doubtemp[n];
	   k = n;

	for(int j=0; j < n; j++)
	{
	doubtemp[j] = a[j];		
	}

	for(int i = 0;i < n; i++)
	{
	squared += (doubtemp[i] - avg) * (doubtemp[i] - avg);
	}
	strd = sqrt(squared / k);
return strd;    
}

