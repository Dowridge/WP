//       Course: CS3420-01 Data Structures, Fall 2016
//         Name: Dowridge, Malique
//   Assignment: P1.2
//Date assigned: 09/01/2016
//     Due date: 09/07/2016
//       Remark: This program displays the different types of ways objects can be manipulated

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// container class interface
class container {
public:
	container();
	// Postcondition: all data array elements of the container are initialized to 0 and data member count is set to -1
	
	container( const container &);
	//  Precondition: must be passed an object
	// Postcondition: assigns the calling object to the object passed by reference
	
	void insert(int);
	//  Precondition: container  must not be full
	// Postcondition: if the container is not full, insert the value passed to the function into the first available data array element 
	//  and increment count by 1; otherwise , display "The container is full: no insertion made and program terminated!" 

	bool isEmpty();
	// Postcondition: return true if container is empty; return false otherwise
	
	bool isFull();
	// Postcondition: return true if container is full; return false otherwise

	void deleter();
	//  Precondition: the container  must not be empty
	// Postcondition: if the container is not empty, remove the last element (most recently) stored into the data array of the container;                    
	//otherwise display "Container is empty; program terminated!"

	void undelete();
	// Postcondition: the most recently removed value is restored or undeleted
	
	void sort();
	//  Precondition: container contains at least two values 
	// Postcondition: all values stored in the container have been sorted in ascending order
	
	void display();
	// Postcondition: displays all values currently stored the container
	
	container operator=(const container &c);
	//  Precondition: must be passed a object of the class container
	// Postcondition: assigns the calling object to the object passed my reference
	
private:
	const static int CAPACITY = 10;		// specifies storage capacity of a container object, i.e., the size of the container
	int data[CAPACITY];		// stores inserted integer values  
	int count;					// (count + 1) represents how many values are currently stored in the container!
};								// this is because data member "count" will be used as subscript for the data array.

// Implementation of member functions
container::container()
{
	count = -1;	
    		for (int i = 0; i <= count; i++)
			cout << data[i] << '\t';	
}

container::container(const container &c)
{
count = c.count;                      
            for (int i = 0; i < CAPACITY; i++)
            {
             data[i] = c.data[i];  
            }                             
}

void container::insert(int value)
{
 	 static int val = 0;
	if (!isFull())
	{
	val += value;
		data[++count] = val;	// count is used as subscript for "data" array elements

	}
	else {
		cout << "Attempts to insert a value into a full container; program is terminated!";

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
	cout << "Array size =  " << 4 * count + 4 << ", Actual # of values stored in the array = " << count + 1 << endl;
		 	cout << "*** Contents of array ***" << endl; 
	if (count == -1)
	{
		cout << "container is empty!" << endl;
    }
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
    if (count >= 0)
	   return false;
	else 
	   return true;
}

container container :: operator=(const container &c)
{
    container assign;
	count = c.count;
	for(int i = 0; i < CAPACITY; i++)
	data[i]= c.data[i];
}

int main()
{
	container c1;
	
	//container 1
 	cout << "Before inserting any values in the c1 container." << endl;
    c1.display();
 	cout << "\n\nAfter inserting 11 to 99 with incremental steps of 11 into the container" << endl << endl;
 	cout << "container c1 contains: " << endl;
	for (int i = 0; i < 9; i++)
    c1.insert(11);
	c1.display(); 

	//container 2
	cout << "\n\nDeclared c2 as a copy of c1 using a copy constructor." << endl;
	container c2(c1);
	cout << "container c2 contains: " << endl;
	c2.display();


	//container 3
	cout << "\n\nDeclared c3 and assign c2 to c3 with overloaded assignment operator." << endl;
	container c3;
	cout << "container c3 contains: " << endl;	 
	c3 = c2;
	c3.display();

    system("pause");
	return 0;
}


