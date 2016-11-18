#include <iostream>
#include <iomanip>
using namespace std;

void fill2DArray(int a[][10], int& rn, int& cn);
void display_array(int a[][10], int& rn, int& cn);
void trans(int a[][10], int& rn, int& cn);


int main()
{
	const int SIZE = 10;
	const int rowsize = 10, colsize = 10;
    int rn, cl;
	int a[rowsize][colsize] = {0};

    fill2DArray(a, rn, cl);	
   	cout<<endl;
   	cout << "Before transpose: " << endl;
	display_array(a, rn, cl);
	cout << "After transpose: " << endl;
	trans(a, rn, cl);
	display_array(a, rn, cl);
	
system("PAUSE");
return 0;
}

void fill2DArray(int a[][10], int& rn, int& cn)
{
	cout << "Enter the number of rows for the matrix: ";
	cin >> rn;
	
	cout << "Enter the number of columns for the matrix: ";
	cin >> cn;
	
	cout << "\n\nMatrix contains " << rn << " with " << cn << " elements in each row.\n\n";

         for(int i = 0; i < rn; i++)
		 {	
		   cout << "Enter " << cn << " intergers for row # " << i+1 << ":";

		 	  for(int k = 0; k < cn; k++)
		 	  {
	 	 	  cin >> a[i][k];
		 	  }
		 }	
}

void display_array(int a[][10], int& rn, int& cn)
{
	for(int i = 0; i < rn; i++)
	{
		for(int s = 0; s < cn; s++) 
		{
			cout << a[i][s] << '\t';
		}
	cout << endl;
	}	
}

void trans(int a[][10],int& rn, int& cn)
{
 	 int temp, swap;
  	 for(int i=0 ;i < rn; i++)
   	 {
      		 for(int j = 0; j < cn; j++)
      		 {
      		 temp = a[i][j];
      		 a[i][j] = a[j][i];
      		 a[j][i] = temp;
      		 }
	 }
	 swap = rn;
	 rn = cn;
	 cn = swap;
}

