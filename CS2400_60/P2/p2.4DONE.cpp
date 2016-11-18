//       Course: cs2400-60 Computer Science I, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: Program 2.4
//Date assigned: 2/18/16
//     Due date: 2/23/16
//       Remark: This program removes duplicate numbers in an array.

#include <iostream>
#include <iomanip>
using namespace std;

void fill2DArray(int a[][5], int numRows, int rowsize, int colsize, int& rn, int& cn);
// Pre: 
//Post:
void display_array(int a[][5], int numRows, int& rn, int& cn);
// Pre: 
//Post:
void computeSales(int [][5], int qtrlySum[], int& rn, int branchSum[], int& cn);
// Pre: 
//Post:

int main()
{
	const int SIZE = 5;
	const int rowsize = 4, colsize = 5;
    int rn, cl;
	int a[rowsize][colsize] = {0};
	int qtrlySum[colsize] = {0};
	int branchSum[colsize];


    fill2DArray(a, SIZE, rowsize, colsize, rn, cl);	
   	cout<<endl;
	display_array(a, SIZE, rn, cl);
    computeSales(a, qtrlySum,rn, branchSum, cl);

system("PAUSE");
return 0;
}

void fill2DArray(int a[][5],int numRows, int rowsize, int colsize, int& rn, int& cn)
{
	cout << "Enter the number of rows for the matrix: ";
	cin >> rn;
	cout << "Enter the number of columns for the matrix: ";
	cin >> cn;
	cout <<"\n\nMatrix contains "<<rn<<" with " <<cn<<" elements in each row."<<endl<<endl;

         for(int i = 0; i < rn; i++)
		 {	
		   cout << "Enter " << cn << " intergers for row # " << i+1 << ":";

		 	  for(int k = 0; k < cn; k++)
		 	  {
	 	 	  cin >> a[k][i];
		 	  }
		 }	
}

void display_array(int a[][5],int numRows, int& rn, int& cn)
{
	int test = 0;
     for(int i=0; i>= cn; i++) //branch headers
     {
             if(i == 0)           
             cout << setw(20);
     
             else     
             cout << "Branch-" << i << setw(12); 
             
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
		cout << endl;
	}
	
	
}

void computeSales(int a[][5], int qtrlySum[], int& rn, int branchSum[], int& cn)
{
 int sum = 0;
		cout << "\nBranch Sum" << ":" << setw(8);
		
     for(int i = 0; i < cn; i++ )
     {
     qtrlySum[i] = 0;
 
                   for(int j = 0; j < rn; j++)
                   {
				   ;
                   qtrlySum[i] = qtrlySum[i] + a[i][j];
                   
                   
                   }
     }
     
  	 for(int i = 0; i < cn; i++)
  	 {
	   sum += qtrlySum[i];
  	 cout << qtrlySum[i] << setw(13);
     	if(i == cn-1)
		cout << sum;
  	 }


  cout<<endl<<endl;



 for (int j = 0; j<cn; j++ )
	{
	 branchSum[j] = 0;
 	 for (int i = 0; i < rn; i++)
 	 {
 	 branchSum[j] = branchSum[j] + a[i][j];

	}
} 
  for(int i = 0;i < cn; i++)
  cout << branchSum[i] << setw(13);
  cout << "\nThese two numbers above are the sum of the rows." << endl;
  cout << endl; 
}

