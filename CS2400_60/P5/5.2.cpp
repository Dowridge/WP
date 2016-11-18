//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P5.2
//Date assigned: 3/11/2016
//     Due date: 3/22/2016
//       Remark: 
         
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

	  class Student
{
 	  private:
       		  string name;
       		  int q1, q2, mid, final;
       		  double avg; 
	   		  char grade; 
	               
	  public: 
 		 int fillArray()
		 {
    	  cout << "Enter Name, Quiz 1, Quiz 2, Midterm, and Final" << endl;
		  cout << "\n\nEnter name of student: ";
 		  cin >> name >> q1 >>  q2 >> mid >> final;		   
	 	  cout << endl;
		 }

		double average()
		{
  	 	avg = (q1 * 0.125) +  (q2 * 0.125) + (mid * 0.25)+ (final * 0.50);
	 	}

		double convertAvgToLetterGrade()
		{
	   	 if(avg >= 90)
	   	 grade= 'A';
	   	
	   	 else if(avg >= 80)
	   	 grade= 'B';
	   	
	   	 else if(avg >= 70)
	   	 grade= 'C';
	   	
	   	 else if(avg >= 60)
	   	 grade= 'D';
	   	
	   	 else
	   	 grade='F';
	    }

		void display()
	 	{
    	 cout << setw(19) << " Name: " << name  << endl;
	  	 cout << setw(19) << "Quiz #1: " << q1 << endl;
	  	 cout << setw(19) << "Quiz #2: " << q2 << endl;
 	   	 cout << setw(19) << "Midterm: " << mid << endl;    
   		 cout << setw(19) << "Final: " << final << endl;
   		 cout << setw(19) << "Average: " << avg << endl;
   		 cout << setw(19) << "Grade: " << grade << endl;
	  	 }
};

int main()
{
 	Student s1;

 	s1.fillArray();
	s1.average();
	s1.convertAvgToLetterGrade();	
	s1.display();
		
	cout << endl;
    system("PAUSE");
    return 0;
}









