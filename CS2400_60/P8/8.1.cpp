//       Course: CS2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P8.2
//Date assigned: 5/01/2016
//     Due date: 5/08/2016
//       Remark: This is a employee class

#include <iostream>
#include "employee.h"
#include <string>
using namespace std;

Employee::Employee( ) 
:name("No name yet"), ssn("No number yet"), net_pay(0)
    {
        //deliberately empty
    }

Employee::Employee(string the_name, string the_number) 
:name(the_name), ssn(the_number), net_pay(0) 
    {
        //deliberately empty
    }

string Employee::get_name( ) const 
    {
        return name;
    }

string Employee::get_ssn( ) const 
    {
        return ssn;
    }

double Employee::get_net_pay( ) const 
    {
        return net_pay;
    }

void Employee::set_name(string new_name)
    {
        name = new_name;
    }
   

void Employee::set_ssn(string new_ssn)
    {
        ssn = new_ssn;
    }

void Employee::set_net_pay (double new_net_pay)
    {
        net_pay = new_net_pay;
    }

void Employee::print_check( ) const
    {
        cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"
             << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n" 
             << "Check with the author of the program about this bug.\n";
        exit(1);
    }


// Implementation for the Derived Class HourlyEmployee 
HourlyEmployee::HourlyEmployee( ) 
:Employee( ), wage_rate(0), hours(0)
    {
        //deliberately empty
    }

HourlyEmployee::HourlyEmployee(string the_name, string the_number,
                                   double the_wage_rate, double the_hours)
    :Employee(the_name, the_number), wage_rate(the_wage_rate), hours(the_hours)
    {
        //deliberately empty
    }

void HourlyEmployee::set_rate(double new_wage_rate)
    {
        wage_rate = new_wage_rate;
    }

double HourlyEmployee::get_rate( ) const
    {
        return wage_rate;
    }

void HourlyEmployee::set_hours(double hours_worked)
    {
        hours = hours_worked;
    }

double HourlyEmployee::get_hours( ) const
    {
        return hours;
    }

void HourlyEmployee::print_check( )
    {
        set_net_pay(hours * wage_rate);

        cout << "\n________________________________________________\n";
        cout << "Pay to the order of " << get_name( ) << endl;
        cout << "The sum of $" << get_net_pay( ) << " Dollars\n";
        cout << "________________________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << get_ssn( ) << endl;
        cout << "Hourly Employee. \nHours worked: " << hours 
             << " Rate: " << wage_rate << " Pay: $" << get_net_pay( ) << endl; 
        cout << "_________________________________________________\n";
    }


// Interface for the Derived Class SalariedEmployee


SalariedEmployee::SalariedEmployee( ) 
: Employee( ), salary(0)
    {
        //deliberately empty
    }

SalariedEmployee::SalariedEmployee(string the_name, string the_number,
                                  double the_weekly_salary)
: Employee(the_name, the_number), salary(the_weekly_salary)
    {
        //deliberately empty
    }

double SalariedEmployee::get_salary( ) const 
    {
        return salary;
    }

void SalariedEmployee::set_salary(double new_salary)
    {
        salary = new_salary;
    }

void SalariedEmployee::print_check( )
    {
        set_net_pay(salary);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << get_name( ) << endl;
        cout << "The sum of $" << get_net_pay( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << get_ssn( ) << endl;
        cout << "Salaried Employee. Regular Pay: $" 
             << salary << endl; 
        cout << "_________________________________________________\n";
    }
SalesEmployee::SalesEmployee()
{
	
}

double SalesEmployee::get_basePay( ) const
{
	return basePay;
}

double SalesEmployee::get_totalSales( ) const
{
	return totalSales;
}

double SalesEmployee::get_commissionRate( ) const
{
	return commissionRate;
}

void SalesEmployee::set_commission(double totalSales)
    {
        commissionRate = .05 * totalSales;
    }     

SalesEmployee::SalesEmployee(string the_name, string the_number , double basePay,
                           double totalSales)
: Employee(the_name, the_number), basePay(basePay), totalSales(totalSales)
{	
(*this).set_commission(totalSales);
}
    
void SalesEmployee::print_check( )
    {
        
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << get_name( ) << endl;
        cout << "The sum of $" <<basePay + commissionRate << " Dollars\n";
        cout << "$" << basePay << " (basePay)";
        cout << " + $" << commissionRate << " (commissionRate)\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
		cout << "Employee Number: " << get_ssn( ) << endl;
        cout << "_________________________________________________\n";
    }
    
    int main()
	{

	cout << "Salaried Employee";
  	SalariedEmployee emp1("Stefan Dowridge","855651022", 4000);
  	emp1.print_check();
  	
  	cout << "\n\n\nHourly Employee";
	HourlyEmployee emp2;
	emp2.set_name("Andy Dowridge");
	emp2.set_ssn("855651293");
	emp2.set_rate(8.38);
    emp2.set_hours(23);	
	emp2.print_check();

	cout << "\n\n\nSales Employee";
	SalesEmployee sales("Malique Dowridge" , "855650251" , 500, 2000);
  	sales.print_check();	
	}

