//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P6.2
//Date assigned: 04/08/2016
//     Due date: 04/19/2016
//       Remark: This program keeps track of how much money and the rate the users savings
//				will become after a year

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class BankAccount
{ 
public:
	BankAccount();
 	// default constructor
   // Postcondition: Initializes the account balance to $0.00 and the interest rate to 0.0%.

    BankAccount(double balance, double r);
    // Precondition: two values are passed into the object function: double and double
    // Postcondition: Initializes balance and rate according to arguments

    BankAccount(int dollars, int cents, double r);
    // Precondition: three values are passed into the object function: int, int and double
    // Postcondition: Initializes the account balance to $dollars.cents

    BankAccount(int dollars, double r);
    // Precondition: two values are passed into the object function: int and double
    // Postcondition: Initializes the account balance to $dollars.00 and the interest rate to rate percent.

    void update();
    //Postcondition: One year of simple interest is added to the account

    void input();
    // Postcondition: the balance is stored in two separate data members accountDollars and accountCents; 

    void output(); 
    // Postcondition: display both balance and interest ina format shown in the sample output

    double getBalance();
    // Postcondition: returns balance (combine accountDollars and accountCents)

    int getDollars();
    // Postcondition: returns accountDollars

    int getCents();
    // Postcondition: returns accountCents

    double getRate();
    // Postcondition: returns interest rate as a percent.

    void setBalance(double balance);
    // Postcondition: set the accountDollars to the dollar part of balance and centsPart to the cents part of balance (use helper functions!)

    void setBalance(int dollars, int cents);
    // Postcondition: set the calling object of values passed to the function if arguments are both nonnegative or both nonpositive

    void setRate(double newRate);
    // Postcondition: if newRate is nonnegative, it becomes the new rate. Otherwise abort program by calling exit(1) function

    int dollarsPart(double amount);
    // Postcondition: returns the integral part of the "amount" passed to the function

    int centsPart(double amount);
    // Postcondition: returns the fractional part of the "amount" passed to the function

    int round(double number);
    // Postcondition: returns the rounded value of a "number" (an integer) passed to the function

    double fraction(double percent);
    //Postcondition: returns the rounded value of a "number" (an integer) passed to the function

private:
    int accountDollars; 
    int accountCents;
    double rate;	
};

void BankAccount::update()
{
  static_cast<int>(accountDollars = accountDollars + (accountDollars * rate)); 
  static_cast<int>(accountCents = accountCents + (accountCents * rate));
  cout << "In one year Account 2 will grow to:";
}
 void BankAccount::input()
{
      double balance;
 cout << "Enter Balance: $";
 cin >> balance;
 cout << "Rate: ";
 cin >> rate;
 setBalance(balance);
 rate= rate / 100;
}

BankAccount::BankAccount(int dollars, int cents, double r)
{
     cout << "Account 1 initialized as follows:";
     accountDollars = dollars; 
     accountCents = cents;
     rate = r/100;       
     output();      
}

BankAccount::BankAccount(double balance, double r)
{
accountCents = centsPart(balance);  
accountDollars = dollarsPart(balance);  
rate = r;
}

double BankAccount::getBalance()
{
   return accountDollars + accountCents;
}

int BankAccount::getDollars()
{
    return accountDollars;
}

int BankAccount::getCents()
{
    return accountCents;
}

double BankAccount::getRate()
{
    return rate;
}

void BankAccount::setBalance(double balance)
{
     accountCents = centsPart(balance);  
     accountDollars = dollarsPart(balance);  
}

void BankAccount::setBalance(int dollars, int cents)
{
     cout << "Account 1 reset to the following:";
     accountCents = cents;  
     accountDollars = dollars;     
}

void BankAccount::setRate(double newRate)
{
     if (newRate < 0)
     exit(1);
     else
     rate = newRate/100;    
}

int BankAccount::dollarsPart(double amount)
{
    return static_cast<int>(amount);
}

int BankAccount::centsPart(double amount)
{
    double doubleCents = amount * 100;
    int intCents = (round(fabs(doubleCents))) % 100;
    if (amount < 0)
        intCents = -intCents;
    return intCents;
}
void BankAccount::output()
{
 	 cout << setfill('0');
	cout << "\nAccount Balance: $" << accountDollars << "." << setw(2) << accountCents;
	cout << "\nRate: " << rate * 100 << "%" <<"\n\n";
}

int BankAccount::round(double number)
{
    return static_cast<int>(floor(number + 0.5));
}

double BankAccount::fraction(double percent)
{
    return (percent/100.0);
}

BankAccount::BankAccount( )
{
     cout << "Account 2 initialized as follows: ";
     accountDollars = 0; 
     accountCents = 0;
     rate = 0;          
     output();
     cout << endl;           
}

int main()
{
 	double n;
  BankAccount g(1345,52,2.3), s;

  g.setBalance(999,99);
  g.setRate(5.5);
  g.output();
  cout << "Enter new data for account 2: " << endl;
  s.input();
  cout << "\nAccount 2 reset to the following:";
  s.output(); 
  s.update();
  s.output();
  system("PAUSE");  
  return 0;
}
