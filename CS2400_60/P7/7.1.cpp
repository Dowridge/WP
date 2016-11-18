#include <iostream>
#include "savings.h"
#include <string>
#include <iomanip>
using namespace std;

istream& operator>>(istream& in, savingsAcct&)
{
	return in;
}

ostream& operator<<(ostream& out, const savingsAcct& acc)
{
	out << fixed << setprecision(2) << showpoint;
	out <<"Account No: " << acc.acctNo << endl;	
	out << setw(13) <<"Balance: $" << acc.balance << endl;
	out << setw(13) << "Interest: $" << acc.interest << endl;
	return out;
}

double savingsAcct::getAnnualRate()
{
	return annualRate;
}

void savingsAcct::setAnnualRate(double rate)
{
	annualRate = rate;
}

savingsAcct::savingsAcct()
{
	 balance = 0;
	annualRate = 0;
	 interest = 0;
}

savingsAcct::savingsAcct(string acctNum, double amt)
{
	acctNo = acctNum;
	balance = amt;
}

double *savingsAcct::getAddressOfVar_annulRate()
{
	double *s;
	s = &annualRate;
	return s;
}


void savingsAcct::computeIntrest()
{
	interest = (annualRate/12) * balance;
}

double savingsAcct::annualRate;

int main()
{
	cout << "As of now, no object has been declared.\n";
	cout << "However, static data members exist before any object is declared:" << endl;
	cout << "The address of its storage location: " << int(savingsAcct::getAddressOfVar_annulRate()) << endl;
	cout << "Annual interest rate: " << savingsAcct::getAnnualRate() * 100 << "%" << endl << endl;

	cout << "Still no object has declared, we now set the interest rate to 1.5%." << endl;
	savingsAcct::setAnnualRate(0.015);
	cout << "Now, the annual interest rate is: " << savingsAcct::getAnnualRate() * 100 << "%" << endl << endl;

	cout << "We now declare and initialize 2 savingAcct objects." << endl;
	cout << "We also compute interest at the end of 1st month and display their cnotents:\n\n";

	savingsAcct s1("A1234", 5000), s2("A9876", 8000);

	s1.computeIntrest();
	s2.computeIntrest();
	cout << s1 << endl << endl;
	cout << s2 << endl << endl;

	cout <<  "We now display the address of static variable annualRate" << endl;
	cout << "   by calling \"getAddressOfVar_annulRate()\" member function" << endl << endl;
	cout << "Via s1: the address of \"annualRate\" is  " << int(s1.getAddressOfVar_annulRate()) << endl;
	cout << "Via s2: the address of \"annualRate\" is  " << int(s2.getAddressOfVar_annulRate()) << endl;
	cout << "Via s1: the address of \"annualRate\" is  " << int(savingsAcct::getAddressOfVar_annulRate()) << endl;
	cout << "\nIt should be quite clear that static members are indeed \"class-wide!!!\"" << endl;
	cout << "Note: calling a static member function, \"this\" pointer is not involved!!!\n\n";
	system("pause");
    return 0;
}


