#include <iostream>
using namespace std;
void counting();

int main()
{

for(int i=1;i<=5;i++)
	{
	counting();	
	}
	system("Pause");
	return 0;
}


void counting()
{
static int x=0;
cout<<"This function has been called "<<++x<<" times"<<endl;
}
