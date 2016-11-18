//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P2.3
//Date assigned: 2/13/16
//     Due date: 2/23/16
//       Remark: This program is a magic square.

#include <iostream>
using namespace std;

void fill_array(int a[][10], int SIZE, int& rows, int& cols);
// Pre: takes in the size of the array.
//Post: returns the partially filled value of the array.

void display_array(int a[][10], int rows, int cols);
// Pre:  This function reads the numbers stored in each cell.
//Post: Displays the data in each array cell.

bool isMagic(int a[][10]);
// Pre: is passed 2d array size
//Post: returns true of false if the magic squares algorithm is true or false

int main()
{
	const int SIZE = 20;
	int cols, rows;
	int a[10][10], n;	
	bool TF;

	fill_array(a,SIZE, rows, cols);
	display_array(a, rows, cols);
	TF=isMagic(a);
	
	if(TF>0)
	cout <<"\nThe above square IS magic!" << endl;
	else
	cout << "\nThe above square is NOT magic!" << endl;
system("PAUSE");
return 0;
}

void fill_array(int a[][10], int SIZE, int& rows, int& cols)
{

	cout << "Enter the number of rows for the matrix: ";
	cin >> rows;
	cout << "Enter the number of columns for the matrix: ";
	cin >> cols;
	cout <<"\n\nMatrix contains "<<rows<<" with " <<cols<<" elements in each row."<<endl<<endl;

		 for(int i = 0; i < rows; i++)
		 {	
		 cout << "Enter " << cols << " intergers for row # " << i+1 << ":";

		 	  for(int k = 0; k < cols; k++)
		 	  {
	 	 	  cin >> a[k][i];
		 	  }
		 }	
}

void display_array(int a[][10],int rows, int cols)
{
	cout << "\n\n" << rows <<" x " << cols << " matrix contains: " <<endl;
	for(int i = 0; i < rows; i++)
	{
		for(int s = 0; s < cols; s++) 
		{
			cout << a[s][i] << '\t';
		}
		cout << endl;
	}	
}

bool isMagic(int arrayOne[][10])
{
 	 int MAGICNUMBER;
	bool magicSquare = true;     
	int b = 0;                     
	cout<<"\nEnter the sum of any row/column/diagonal: ";
	cin>>MAGICNUMBER;

	while (magicSquare == true && b < 3)
        {
		int sum = 0; 

		for(int i = 0; i < 3; i++)
	 {
			sum = sum + arrayOne[b][i]; 
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
		    sum = sum + arrayOne[i][b];
		}

		b++;

		if(sum != MAGICNUMBER)
        {
            magicSquare = false;
        }
    }
    
	if(magicSquare == true)
        {
         
        int leftDiag = arrayOne[0][0] + arrayOne[1][1] + arrayOne[2][2];
        int rightDiag = arrayOne[2][0] + arrayOne[1][1] + arrayOne[0][2];

	if(leftDiag != MAGICNUMBER || rightDiag != MAGICNUMBER)
        magicSquare = false;
	}
	return magicSquare;
}
