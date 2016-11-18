//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P2.4
//Date assigned: 2/18/16
//     Due date: 2/23/16
//       Remark: This program calculates the sum of rows and  columns and all of their sums.

#include <iostream>
#include <iomanip>
using namespace std;
void fill2DArray(int a[][5], int numRows);
// Pre: takes in the row numbers
//Post:fills the array up with numbers inputed by the user.

void computeSales(int a[][5], int quarterSum[], int numOfquarters, int branchSum[], int numOfbranches);
// Pre: takes in 3 arrays and the row and column numbers.
//Post: display an imcomplete chart of the columns but not the rows.

int main()
{
	const int SIZE = 5;
	const int rowsize = 4, colsize = 5;
    
	int a[rowsize][colsize];
	int qtrlySum[colsize] = {0};
	int branchSum[colsize] = {0};

    fill2DArray(a, rowsize);	
    computeSales(a, qtrlySum, rowsize, branchSum, colsize);

system("PAUSE");
return 0;
}

void fill2DArray(int a[][5], int rn)
{
         for(int i = 0; i < rn; i++)
		 {	
		   cout << "Enter 5 intergers for row # " << i+1 << ":";

		 	  for(int k = 0; k < 5; k++)
		 	  {
	 	 	  cin >> a[k][i];
		 	  }
		 }	
}


void computeSales(int a[][5], int quarterSum[], int numOfquarters, int branchSum[], int numOfbranches)
{
     int test = 0, qSum = 0, bSum = 0;
     
     for(int i = 0; i < numOfbranches; i++)
     {
     quarterSum[i] = 0;
 
                   for(int j = 0; j < numOfquarters; j++)
                   {
                   quarterSum[i] = quarterSum[i] + a[i][j];
                   }
     }
     
     for(int i = 0; i < numOfquarters; i++)
     {
     branchSum[i] = 0;
 
                    for(int j=0; j < numOfquarters; j++)
                    {
                    branchSum[i] = branchSum[i] + a[j][i];
                    }
     }
 
     cout<<setw(20);
     
     for(int i = 1; i <= numOfbranches; i++)
     {
     cout << "Branch-" << i << setw(12);
     }
             cout << "Sum";  
       
	for(int i = 0; i < numOfquarters; i++)
	{
            
		cout << "\nQuarter-" << i+1 << ":" << setw(10);
                     for(int s = 0; s < numOfbranches; s++) 
		             {
			         cout << a[s][i] << setw(12);
			         if(s == numOfquarters)
			         cout << branchSum[i];
			         test += a[s][i];
		             }
	}
       
		cout << "\nTotal:" << setw(14);
		for (int i = 0; i < 5; i++)
		{
        cout << quarterSum[i] << setw(12);
        }
  cout << test << endl;;
}

