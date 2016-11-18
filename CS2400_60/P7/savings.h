#ifndef savings_h
#define savings_h
#include <iostream>

using namespace std;

class savingsAcct
{
	friend istream& operator>>(istream&, savingsAcct&);
	friend ostream& operator<<(ostream&, const savingsAcct&);
public:
	savingsAcct();
	savingsAcct(string acctNum, double amt);
	// Postcondition: balance is set to the value passed to parameter amt
	static double * getAddressOfVar_annulRate();
	// Postcondition: return the address of static variable annualRate (should the same for all objects!)
	static double getAnnualRate();
	// Postcondition: returns annual interest rate
	static void setAnnualRate(double rate);	// change the annual interest rate
											// Postcondition: annualRate has been changed to the value passed to parameter rate
	void computeIntrest();
	// Interest is computed at the end of each month using monthly interest rate (i.e.,annualRate/12)
	// Postcondition: interest is computed at the end of the month using the current balance

private:
	string acctNo;		// e.g., A1234
	double balance;
	static double annualRate;  	// classwide; store in a memory location shared by all objects
	double interest;
	// monthly interest
};
#endif
