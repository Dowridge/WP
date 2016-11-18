//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P6.1
//Date assigned: 04/08/2016
//     Due date: 04/19/2016
//       Remark: This program is a clock which uses various functions to set the time.

#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
public:
       
	Time( int h = 0, int m = 0, int s = 0 );
	//   Precondition: three numbers are passed to this function.
	// Postconditions: if no parameter is supplied in declaration, the declared object is initialized with default values of 0's
	// Otherwise the declared is initialized to the values passed to h, m, and s.

	void setTime( int, int, int ) const;
	//  Precondition: three numbers are passed into this set function
	// Postcondition: the calling object will be set to the three values passed to the function

	void setHour( int );
	//  Precondition: a number is passed into this set function
	// Postcondition: data member hour is set to the value passed to the function

	int getHour() const;
	// Postcondition: value stored in data member hour of the calling object is returned

	void setMinute(int);
	//  Precondition: a number is passed into this set function
	// Postcondition: data member minute is set to the value passed to the function

	int getMinute() const;
	// Postcondition: value stored in data member minute of the calling object is returned

	void setSecond(int);
	//  Precondition: a number is passed into this set function
	// Postcondition: data member second is set to the value passed to the function

	int getSecond() const;
	// Postcondition: value stored in data member second of the calling object is returned

    void tick();
	// Postcondition: increment the current time of the calling Time object by one second. 

	void printUniversal() const;
	// Postcondition: Contents of the object are display in the universal time format

	void printStandard();
	// Postcondition: Contents of the object are display in the standard time format

private:
	int hour;	// 0 - 23
	int minute;	// 0 - 59
	int second;	// 0 - 59
};

Time:: Time(int h, int m , int s)
{
hour = h;
minute = m;
second = s;            
}

void Time::setHour(int n)
{
hour = n;
}

void Time::setMinute(int n)
{
minute = n;
}

void Time::setSecond(int n)
{
second = n;
}

void Time::printStandard()
{	
	 cout << "\nStandard Time: " << endl;
     cout << setfill('0');
     cout << setw(2) << hour-12 << ":" << setw(2) << minute << ":" << setw(2) << second;
     
     if (hour <12)
     cout << " A.M" << endl;
     else
     cout << " P.M" << endl;
}

void Time::printUniversal() const
{
	 cout << "\nUniversal Time: " << endl;
     cout << setfill('0');
     cout << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
	 if (hour < 12)
     cout << " A.M" << endl;
     else
     cout << " P.M" << endl; 
}

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

int Time::getSecond() const
{
	return second;
}

void Time::tick()
{
     second++;
         if(second >= 60)
         {
         second = 0;
         minute++;
                  if (minute >= 60)
                  {
                  minute = 0;
                  hour++;
                         if(hour > 12)
                         {
                         hour = 0;
                         hour++;
                         }
                  }                       
          }                  
}


int main()
{
    Time t1, t2(21, 15, 35);
    t2.printStandard();
    t2.printUniversal();   
	
	for(int i = 0; i < 500; i++) //Appoximately 8 mins and 33 seconds?
    {
    t2.tick();
    }
    cout << "\nThe time below is after approximately 8 minutes:" << endl;
    
    t2.printStandard();
    t2.printUniversal();
	
	cout << "\nBelow is the set functions in action:" << endl;
	t1.setHour(12);
	t2.setMinute(0);     
 	t1.setSecond(0);
 	t1.printUniversal();
    cout << endl; 

    system("PAUSE");
}
