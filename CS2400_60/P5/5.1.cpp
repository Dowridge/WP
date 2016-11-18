//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P5.1
//Date assigned: 3/11/2016
//     Due date: 3/22/2016
//       Remark: This program is reports back to the user what the final grade
//		of a student is.
         
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct student 
{
       string name;
       int q1, q2, mid, final;
       double avg; 
       char grade;       
};

void display(student &obj);
// Pre: takes in the student object.
//Post: Displays the student object based on the inputs given by fillArray function.
       
int fillArray(student[]);
// Pre: Takes in a student array.
//Post: Returns the number of student.

double avg(student s[], int i, int n);
// Pre: Takes in a student array and the two values which are the student numbers.
//Post: Returns the average and stores it in the array.

double convertAvgToLetterGrade(student s[], int n);
// Pre: Takes in the student array and partially filled array value.
//Post: returns the letter grade.

int main()
{
    int n;
    double average;
    student s[10];
    n = fillArray(s);    
	
    for(int i = 0; i < n; i++)
    {
	 	average = avg(s, i ,n);	
  		convertAvgToLetterGrade(s, n);
 		display(s[i]);
 		cout << endl;
    }
	cout << endl;
    system("PAUSE");
    return 0;
}

void display(student &obj)
{
    	cout << setw(19) << " SID: " << obj.name  << endl;
    	cout << setw(19) << "Quiz #1: " << obj.q1 << endl;
    	cout << setw(19) << "Quiz #2: " << obj.q2 << endl;
    	cout << setw(19) << "Midterm: " << obj.mid << endl;    
	cout << setw(19) << "Final: " << obj.final << endl;
	cout << setw(19) << "Average: " << obj.avg << endl;
	cout << setw(19) << "Grade: " << obj.grade << endl;
}

int fillArray(student s[])
{
     int j;
     cout << "Enter the amount of student scores you wish to input: ";
     cin >> j;
     
     cout << "Enter Name, Quiz 1, Quiz 2, Midterm, and Final" << endl;
     
 	 for(int i = 0; i < j ; i++)
	 {
 	  		 cout << "\n\nEnter name of student: ";
	 		 cin >> s[i].name >> s[i].q1 >>  s[i].q2 >> s[i].mid >> s[i].final;	 
	 }
	 cout << endl;
	 return j;
}

double avg(student s[], int i , int n)
{
 	 s[i].avg = 0;
  	 s[i].avg += (s[i].q1 * 0.125) +  (s[i].q2 * 0.125) + (s[i].mid * 0.25)+ (s[i].final* 0.50);
}

double convertAvgToLetterGrade(student s[], int n)
{
 	   for(int i = 0; i < n; i++)
	   {
	   	if(s[i].avg >= 90)
	   	s[i].grade ='A';
	   	
	   	else if(s[i].avg >= 80)
	   	s[i].grade ='B';
	   	
	   	else if(s[i].avg >= 70)
	   	s[i].grade ='C';
	   	
	   	else if(s[i].avg >= 60)
	   	s[i].grade ='D';
	   	
	   	else
	   	s[i].grade ='F';
	   }	
}
