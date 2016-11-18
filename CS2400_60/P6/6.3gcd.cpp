//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P6.3
//Date assigned: 04/08/2016
//     Due date: 04/19/2016
//       Remark: This program predorms math operations with rational numbers

#include <iostream>
using namespace std;
class rational
{
public:
	rational(int n = 0 , int d = 0 );
	//  Precondition: two values are passed into the function
	// Postcondition: if nothing is passed to the constructor, declared object is initialized to the default values
	//                	otherwise, declared object is initialized to values passed to n and d

	rational add(const rational &r2) const;
	//  Precondition: rational object is passed into the object function
	// Postcondition: sum of the calling object (*this) and r2 is returned

	rational add(const rational &r1, const rational &r2) const;
	//  Precondition: two rational objects are passed into the object function
	// Postcondition: the sum of r1 and r2 is stored in the calling object *this

	rational subtract(const rational &r2) const;
	//  Precondition: rational object is passed into the object function 
	// Postcondition: difference of the calling object (*this) - r2 is returned

	rational subtract(const rational &r1, const rational &r2) const;
	//  Precondition: two rational objects are passed into the object function
	// Postcondition: the difference of r1 - r2 is stored in the calling object *this

	rational multiply(const rational &r2) const;
	//  Precondition: rational object is passed into the object function
	// Postcondition: the product of the calling object (*this) * r2 is returned

	rational divide(const rational &r2) const;
	//  Precondition: rational object is passed into the object function
	// Postcondition: the quotient of the calling object (*this) / r2 is returned

	bool greaterThan(const rational &r2) const;
	//  Precondition: rational object is passed into the bool object function
	// Postcondition: return true if *this is greater than r2; false otherwise

	void inputRational();
	// Postcondition: the calling object is loaded with values entered by the user

	void displayRational();
	// Postcondition: displays the contents of the calling object

private:
	int num;
	int denom;	
	rational gcd();
	// Postcondition: changes the contents or num and denom
	//to a reduced form.
};

rational::rational(int n, int d)
{
num = n;
denom = d;
}

void rational::inputRational()
{
	cout << "\nEnter a rational number" << endl;
	cout << "Enter the numerator: ";
	cin >> num;
	cout << "Enter the denominator: ";
	cin >> denom;
	gcd();
}

void rational::displayRational()
{
	cout << num << " / " << denom;
}

rational rational::add(const rational &r2) const
{

int n = num * r2.denom + denom * r2.num;
int d = denom * r2.denom;
return rational(n, d);
}

rational  rational::subtract(const rational &r2) const
{
int n = num * r2.denom - denom * r2.num;
int d = denom * r2.denom;
return rational(n, d);
}

rational rational::subtract(const rational &r1, const rational &r2) const
{
int n = r1.num * r2.denom - r1.denom * r2.num;
int d = r1.denom * r2.denom;
return rational(n, d);
}
	
rational rational::add(const rational &r1, const rational &r2) const
{
int n = r1.num * r2.denom + r1.denom * r2.num;
int d = r1.denom * r2.denom;
return rational(n, d);
}

rational rational::multiply(const rational &r2) const
{
int n = num * r2.num;
int d = denom * r2.denom;
return rational(n, d);
}

rational rational::divide(const rational &r2) const
{
int n = num * r2.denom;
int d = denom * r2.num;
return rational(n, d);
}

bool rational::greaterThan(const rational &r2) const
{
if(num >= r2.num && denom <= r2.denom)
return true;
else
return false;
}

rational rational::gcd()
{
	cout << "Reducing Fracions" << endl;
 	for(int i = num * denom; i > 1; i--)
    {
        if((num % i) == 0 && (denom % i) == 0)
        {
            num = num / i;
            denom = denom / i;
        }
    }
}

int main()
{
 	bool greater;
	rational a, b, op;
	a.inputRational();
	b.inputRational();
	greater = a.greaterThan(b);
	
	if (greater == 1)
	{
 	   a.displayRational();
	   cout << " >= " ;
	   b.displayRational();
	}
	else
	{
	 	a.displayRational();
		cout << " <= " ; 
		b.displayRational();
	}
	
	cout << "\nAddition: ";
	op = a.add(b);
	op.displayRational();
	
	cout << "\nAddition V2: ";
	op = op.add(a,b);
	op.displayRational();
	
	cout << "\nSubtraction: ";
	op = a.subtract(b);
	op.displayRational();
	
	cout << "\nSubtraction V2: ";
	op = op.subtract(a,b);
	op.displayRational();
	
	cout << "\nMultiplication: ";
	op = a.multiply(b);
	op.displayRational();
	
	cout << "\nDivision: ";
	op = a.divide(b);
	op.displayRational();
	
	cout << endl;
	system("Pause");
	return 0;
}
