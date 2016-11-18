#include <iostream>
#include <iomanip>
using namespace std;

void f();

int x = 5;

int main()
{
	cout << "x = " << x << endl;

	int x = 6;
	cout << "x = " << x << endl;

	{
		int x = 7;
		cout << "x = " << x << endl;
	}
	cout << "x = " << x << endl;

	f();

	return 0;
}
void f()
{
	cout << "x = " << x << endl;
	
	int x = 8;
	cout << "x = " << x << endl;
}

