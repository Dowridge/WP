//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: Program 2.4
//Date assigned: 2/18/16
//     Due date: 2/23/16
//       Remark: This program removes duplicate numbers in an array.

#include <iostream>
#include <iomanip>
using namespace std;

void fill2DArray(int a[][5], int numRows);
// Pre: takes in the row numbers
//Post:fills the array up with numbers inputed by the user.

void computeSales(int [][5], int qtrlySum[], int rn, int branchSum[], int cn);
// Pre: takes in 3 arrays and the row and column numbers.
//Post: display an imcomplete chart of the columns but not the rows.

int main()
{
	const int SIZE = 5;
	const int rn = 4, cn = 5;
   
	int a[rn][cn] = {0};
	int qtrlySum[cn] = {0};
	int branchSum[cn];

   	fill2DArray(a, rn);	
    	computeSales(a, qtrlySum,rn, branchSum,cn);

system("PAUSE");
return 0;
}

void fill2DArray(int a[][5],int numRows)
{
         for(int i = 0; i < numRows; i++)
		 {	
		   cout << "Enter 5 intergers for row # " << i+1 << ":";
		 	  for(int k = 0; k < 5; k++)
		 	  {
	 	 	  cin >> a[k][i];
		 	  }
		 }	
}


void computeSales(int a[][5], int qtrlySum[], int rn, int branchSum[], int cn)
{
	int sum = 0;
     	cout<<setw(25);
 
  	for(int i=0; i <= cn; i++) //branch headers
     		{
             		if(i == 0)           
             		cout << setw(20);
            		else     
             		cout << "Branch-" << i+1 << setw(12); 
            		if(i == cn)
			cout << "Sum";  
   		}
    
	for(int i=0; i < rn; i++)
	{      
	cout << "\nQuarter-" << i+1 << ":" << setw(10);
		for(int s = 0; s < cn; s++) 
		{      
			cout << a[s][i] << setw(12);	
		}
	}
	
	cout << "\nBranch Sum" << ":" << setw(8);
		
     	for(int i = 0; i < cn; i++ )
     	{
     	qtrlySum[i] = 0;
 
                   for(int j = 0; j < rn; j++)
                   {
                   qtrlySum[i] = qtrlySum[i] + a[i][j];
                   }
     	}
     
     	for(int i = 0; i < cn; i++ )
     	{
     	branchSum[i] = 0;
 
                   for(int j = 0; j < rn; j++)
                   {
                   branchSum[i] = branchSum[i] + a[i][j];
                   }
     	}
     
  	for(int i = 0; i < cn; i++)
  	{
	  	sum += qtrlySum[i];
  	 	cout << qtrlySum[i] << setw(13);
     			if(i == cn-1)
			cout << sum;
  	}

	cout <<endl<<endl;

 		for (int j = 0; j<cn; j++ )
		{
		 branchSum[j] = 0;
 	 		for (int i = 0; i < rn; i++)
 	 		{
 	 		branchSum[j] = branchSum[j] + a[i][j];
			}
		} 
}