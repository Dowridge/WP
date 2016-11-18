#include <iostream>
#ifndef employee_h	
#define employee_h

using namespace std;
class Employee
    {
    public:
        Employee( );
	//  Precondition: default constructor class
	// Postcondition: constructor is called

        Employee(string the_name, string the_ssn);
	//  Precondition: 2nd constructor that takes in 2 strings 
	// Postcondition: sets the name and the ssn to the parameters

        string get_name( ) const;
	// Postcondition: retuns the name

        string get_ssn( ) const;
	// Postcondition:returns the ssn

        double get_net_pay( ) const;
	// Postcondition: returns the

        void set_name(string new_name);
	//  Precondition:takes in a string object
	// Postcondition: sets the name equal new_name

        void set_ssn(string new_ssn);
	//  Precondition:takes in string object
	// Postcondition:sets new_ssn to ssn

        void set_net_pay(double new_net_pay);
	//  Precondition: takes in double type
	// Postcondition: sets new_net_pay to net_pay

    virtual void print_check( ) const;
	// Postcondition: prints the data

    private:
        string name; 
        string ssn; 
        double net_pay;
    };

class HourlyEmployee 
:public Employee 
    {
    public:
        HourlyEmployee( );
	//  Precondition: default constructor class
	// Postcondition: constructor is called

        HourlyEmployee(string the_name, string the_ssn,
                           double the_wage_rate, double the_hours);
	//  Precondition: 2nd constructor that takes in 2 strings 
	// Postcondition: sets the name and the ssn to the parameter

        void set_rate(double new_wage_rate);
	//  Precondition: takes in double type
	// Postcondition: sets hours_worked to hours


        double get_rate( ) const;
	// Postcondition: returns rate;

        void set_hours(double hours_worked);
	//  Precondition: takes in double type
	// Postcondition: sets hours_worked to hours

        double get_hours() const;
	// Postcondition: returns hours

   	void print_check();
	// Postcondition: prints the data

    private:
        double wage_rate; 
        double hours;
    };

class SalariedEmployee 
:public Employee
    {
    public:
        SalariedEmployee( );
	//  Precondition: default constructor class
	// Postcondition: constructor is called

        SalariedEmployee (string the_name, string the_ssn,
                                  double the_weekly_salary);
        double get_salary( ) const;
	// Postcondition: returns salary

        void set_salary(double new_salary);
	//  Precondition: takes in double type
	// Postcondition: sets new_salary to salary
      	void print_check( );
	// Postcondition: prints the data

    private:
        double salary;
    };
    
class SalesEmployee
:public Employee
	{
	public:
	SalesEmployee( );
	//  Precondition: default constructor class
	// Postcondition: constructor is called

        SalesEmployee(string the_name, string the_number , double basePay,
                           double totalSales);
	
        double get_basePay( ) const;
	// Postcondition: returns basePay
	
        double get_totalSales( ) const;
	// Postcondition: returns totalSales

	void set_commission(double);
	//  Precondition: takes in double type
	// Postcondition: sets double type to commissionRate


        double get_commissionRate( ) const;
	// Postcondition: retuns commisionRate
            
      
	void print_check( );
	//Postcondition: prints the data

	private:
	double basePay, totalSales, commissionRate;

	};

    #endif
