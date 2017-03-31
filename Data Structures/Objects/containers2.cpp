//       Course: CS3420-01 Data Structures, Fall 2016
//         Name: Dowridge, Malique
//   Assignment: P1.1
//Date assigned: 09/01/2016
//     Due date: 09/07/2016
//       Remark: This program displays the different types of ways objects can be manipulated


#include <iostream>
#include <iomanip>
#include <cstdlib>	// for exit function.
#include <ctime>
using namespace std;

// container class interface
class container {
public:
	container();
	// Postcondition: all data array elements of the container are initialized to 0 and data member count is set to -1
	
	void insert(int);
	//  Precondition: container  must not be full
	// Postcondition: if the container is not full, insert the value passed to the function into the first available data array element 
	//		    	      and increment count by 1; otherwise , display "The container is full: no insertion made and program terminated!" 

	bool isEmpty();
	// Postcondition: return true if container is empty; return false otherwise
	
	bool isFull();
	// Postcondition: return true if container is full; return false otherwise

	void deleter();
	//  Precondition: the container  must not be empty
// Postcondition: if the container is not empty, remove the last element (most recently) stored into the data array of the container;                    //                           otherwise display "Container is empty; program terminated!"
	void undelete();
	// Postcondition: the most recently removed value is restored or undeleted
	
	void sort();
	//  Precondition: container contains at least two values 
	// Postcondition: all values stored in the container have been sorted in ascending order
	
	void display();
	// Postcondition: displays all values currently stored the container
private:
	const static int CAPACITY = 10;		// specifies storage capacity of a container object, i.e., the size of the container
	int data[CAPACITY];		// stores inserted integer values  
	int backup[CAPACITY];
	int count;					// (count + 1) represents how many values are currently stored in the container!
};								// this is because data member "count" will be used as subscript for the data array.

// Implementation of member functions
container::container()
{
	count = -1;		
	for (int i = 0; i < CAPACITY; i++)
		data[i] = 0;
}

void container::insert(int value)
{
	if (!isFull())
	{
		data[++count] = value;	// count is used as subscript for "data" array elements
		cout << setw(4) << value << " has been inserted in data[" << count << "]." << endl;
	}
	else {
		cout << "Attempts to insert a value into a full container; program is terminated!";
		exit (1);
	}
}


void container::sort()
{
	int pass, c, temp;
	if (count >= 1)			// perform sort operation only when the data array contains at least two elements
	{
		for (pass = 1; pass < count; pass++)
			for (c = 0; c <= count - pass; c++)
				if (data[c] > data[c + 1]) {
					temp = data[c];
					data[c] = data[c + 1];
					data[c + 1] = temp;
				}
	}
}

void container::display()
{
	cout << "The 'container' contains the following " << count + 1 << " value(s):\n";
	if (count == -1)
		cout << "*** data array is empty!" << endl;
	else
	{

		for (int i = 0; i <= count; i++)
			cout << data[i] << '\t';
		cout << endl;
	}
}

void container::deleter()	// logical removal!
{

	if (!isEmpty())
	{
	
		cout << "  data[" << count-- << "] is 'logically' removed from the container!" << endl;
		
	}
	else 
	{
		cout << "Attempts to remove a value from an empty container; program is terminated!";
		exit (1);
	}
}

void container:: undelete()
{
count++;		
}

bool container:: isFull()
{
	bool status;
	
	if (data[count] == CAPACITY)
		status = true;
	else
		status = false;

	return status;
}

bool container:: isEmpty()
{
if (count >=0)
return false;
else true;
}

int main()
{
	container c;
	srand(static_cast<unsigned int>(time(0)));
	cout << "We now insert 10 random integer values into the container:\n";
	for (int i = 0; i < 10; i++)
	c.insert(rand() % 99 + 1);

	cout << "\nThe contents of the container are: " << endl;
	c.display();

	c.sort();
	cout << "After sort: " << endl;
	c.display();

	cout << "We now remove all values in the container:\n";

	for (int i = 0; i < 10; i++)
	c.deleter();

	cout << endl;
	c.display();

	cout << "\nWe now perform the 'undelete' operation three times:\n";
	c.undelete();
	c.undelete();
	c.undelete();
	c.display();

	return 0;
}


