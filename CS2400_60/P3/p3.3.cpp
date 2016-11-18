//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P3.3
//Date assigned: 2/26/16
//     Due date: 3/8/16
//       Remark: This program a dynamically allocated magic square.

#include <iostream>
using namespace std;

void fill_array(int **a, int& rows, int& cols);
// Pre: takes in the size of the array.
//Post: returns the partially filled value of the array.

void display_array(int **a, int rows, int cols);
// Pre:  This function reads the numbers stored in each cell.
//Post: Displays the data in each dynamic array cell.

bool isMagic(int **a);
// Pre: the dynamic array is passed into the function.
//Post:returns true or false if the square is perfect.

int main()
{
	int **a, rows, cols;
	bool TF;
	
	cout << "Enter the number of rows for the matrix: ";
	cin >> rows;
	cout << "Enter the number of columns for the matrix: ";
	cin >> cols;

	a=new int *[rows];
	for (int i=0; i < rows; i++)
	a[i] = new int [cols];
	assert(a!=0);

	fill_array(a, rows, cols);
	display_array(a, rows, cols);
	TF=isMagic(a);
	
	if(TF>0)
	cout <<"\nThe above square IS magic!" << endl;
	else
	cout << "\nThe above square is NOT magic!" << endl;
	delete [] a;
	
system("PAUSE");
return 0;
}

void fill_array(int **a, int& rows, int& cols)
{

	cout << "\n\nMatrix contains " << rows << " with " << cols << " elements in each row.\n\n";

		 for(int i = 0; i < rows; i++)
		 {	
		 cout << "Enter " << cols << " intergers for row # " << i+1 << ":";

		 	  for(int k = 0; k < cols; k++)
		 	  {
	 	 	  cin >> a[k][i];
		 	  }
		 }	
}

void display_array(int **a, int rows, int cols)
{
	cout << "\n\n" << rows << " x " << cols << " matrix contains: " << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int s = 0; s < cols; s++) 
		{
			cout << a[s][i] << '\t';
		}
		cout << endl;
	}	
}

bool isMagic(int **a)
{
 	 int MAGICNUMBER;
	bool magicSquare = true;     
	int b = 0;                     
	cout << "\nEnter the sum of any row/column/diagonal: ";
	cin >> MAGICNUMBER;

	while (magicSquare == true && b < 3)
        {
		int sum = 0; 

		for(int i = 0; i < 3; i++)
	 {
			sum = sum + a[b][i]; 
        }
		
		b++; 

		if(sum != MAGICNUMBER)
			magicSquare = false;
        }
	b = 0;

	while (magicSquare == true && b < 3)
    {
		int sum = 0;

		for(int i = 0; i < 3; i++)
		{
		    sum = sum + a[i][b];
		}

		b++;

		if(sum != MAGICNUMBER)
        {
            magicSquare = false;
        }
    }
    
	if(magicSquare == true)
        {
         
        int leftDiag = a[0][0] + a[1][1] + a[2][2];
        int rightDiag = a[2][0] + a[1][1] + a[0][2];

	if(leftDiag != MAGICNUMBER || rightDiag != MAGICNUMBER)
        magicSquare = false;
	}
	return magicSquare;
}
