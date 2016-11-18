//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P4.1
//Date assigned: 2/26/16
//     Due date: 3/10/16
//       Remark:  This program sorts student scores from least to greatest
         
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct student 
{
       string sid;
       string name;
       int credits;
       double gpa;
};

void swap(student &s1, student &s2);
// Pre: takes in two student objects
//Post: sorts the student inputs

void sort(student [], int n);
// Pre: takes in the student array and the number of students desired by user.
//Post: sorts the student inp

void display(student &obj);
// Pre: takes in the student object.
//Post: Displays the student object based on the inputs given by fillArray function.
       
int fillArray(student[]);
// Pre: Takes in a student array.
//Post: Returns the number of student.

int main()
{
    int n;
    student s[10];
	n = fillArray(s);    
    
    cout << "\n\nStudent Scores by input: " << endl << endl;
    
    for(int i = 0; i < n; i++)
    {
	display(s[i]);
	cout << endl;
    }
    
    sort(s,n);
   	cout << "\n\nStudent Info Sorted by GPA: " << endl << endl;
   	
    for(int i = 0; i < n; i++)
    {
	display(s[i]);
	cout << endl;
	}
	cout << endl;
	
    system("PAUSE");
    return 0;
}

void display(student &obj)
{
    cout << setw(19) << " SID: " << obj.sid  << endl;
    cout << setw(19) << "Last/First Name: " << obj.name << endl;
    cout << setw(19) << "Credits: " << obj.credits << endl;
    cout << setw(19) << "GPA: " << obj.gpa << endl;    
}

void swap(student &s1, student &s2)
{
 student temp;
 temp = s1;
 s1 = s2;
 s2 = temp;
}

int fillArray(student s[])
{
     int j;
     cout << "How many student scores do you wish to input? ";
     cin >> j;
     
 	 for(int i = 0; i <j ; i++)
	 {
 	 cout << "\nEnter SID for entry " << i+1 << ":";
	 cin >> s[i].sid;
	 
	 cout << "Enter name for entry " << i+1 << ":";
	 cin >> s[i].name;
	 
	 cout << "Enter credits for entry " << i+1 << ":";
	 cin >> s[i].credits;
	 
	 cout << "Enter gpa for entry " << i+1 << ":";
	 cin >> s[i].gpa;
	 }
	 cout << endl;

	 return j;
}

void sort(student s[], int n)
{
 	 for (int pass = 1; pass < n; pass++)
 	 {
  	 for(int c = 0; c <= n-1-pass;c++)
			if(s[c].gpa > s[c+1].gpa)
			swap(s[c], s[c+1]);
	}	
}
