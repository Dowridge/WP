//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P2.1
//Date assigned: 2/13/16
//     Due date: 2/23/16
//       Remark: This program displays the average and standard deviation of a list of scores.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int fillArray(int score[], int size);
// Pre: takes in the size of the array.
//Post: returns the partially filled value of the array.

void displayArray(int score[], int n);
// Pre:  This function reads the numbers stored in each cell
//Post: Displays the data in each array cell

double computerStandardDeviation(int score[], int n, double avg);
// Pre: takes in the array name and the number of elements filled. 
//Post: returns the standard deviation

double computeAvg(int score[], int n);	
// Pre: take the array and the partially filled size of the array
//Post: returns the average of all the array elements.

int main()
{
	const int SIZE = 20;
	int score[SIZE], n;
	double avg, devi;

	n = fillArray(score, SIZE);
	displayArray(score, n);
	avg = computeAvg(score, n);
	devi = computerStandardDeviation(score, n, avg);
	cout << "\nTotal # of Students: " << n << endl;
	cout << fixed << setprecision(2);
	cout << setw(21) << "Class Average: "<< avg << endl;
	cout << setw(21) << "Standard Deviation: " << devi;
	cout<<endl;
system("PAUSE");
return 0;
}

int fillArray(int score[],int SIZE)
{
	int i = 0;
	int num;
	cout << "Enter up to " << SIZE << " numbers, -99 to end the list."<<endl;
	
	do
	{
		cout << "Enter a number: ";
		cin >> num;
		
	        if(num==-99)
            {
            break;
            }	
		score[i]=num;
		i++;

		if (i == SIZE)
		{
			cout << "The array is full; no more  value can be stored!" << endl;
			num = -99;
		}	
	} while (num !=-99);
	return i;
}

void displayArray(int score[], int n)
{
	cout << "\n\nListing of all student scores: " << endl;
   		for(int i = 0; i < n; i++)
   		{
   		cout << score[i] <<'\t';
		}  
	cout << endl;    
}

double computeAvg(int score[], int n)
{
    	double allscores = 0, avg;

		for(int i = 0; i < n; i++)
		{
		allscores+= score[i];        
		}      
		avg = allscores / n;      
return avg;  
}

double computerStandardDeviation(int score[], int n, double avg)
{
double devi, squared=0, strd, k;
int doubtemp[n];
k=n;

	for(int j=0; j<n; j++)
	{
	doubtemp[j]=score[j];		
	}

	for(int i=0;i<n;i++)
	{
	squared+= (doubtemp[i] - avg) * (doubtemp[i] - avg);
	}
	strd = sqrt(squared / k);

return strd;    
}

