//       Course: cs2400-60 Computer Science II, Spring 2016
//         Name: Dowridge, Malique
//   Assignment: P6.4
//Date assigned: 04/08/2016
//     Due date: 04/19/2016
//       Remark: This is an enhanced version of the rational numbers program from 6.3

#include <iostream>
using namespace std;
class rational
{
	friend istream& operator>>(istream & in, rational &robj);
	// prompts the user to enter two values for numerator and denominator of a rational number
	// Postcondition: the calling object is loaded with values entered by the user

	friend ostream& operator<<(ostream & out, rational &robj);
	// Postcondition: displays the contents of the calling object in the following format:
	
public:
	rational(int n = 0, int d = 1);
	// constructor with default parameters
	// Postcondition: if nothing is passed to the constructor, declared object is initialized to the default values

	rational operator+(const rational &r2) const;
	// Postcondition: sum of the calling object (*this) and r2 is returned

	rational operator-(const rational &r2) const;
	// Postcondition: difference of the calling object (*this) - r2 is returned

	rational operator*(const rational &r2) const;
	// Postcondition: the product of the calling object (*this) * r2 is returned

	rational operator/(const rational &r2) const;
	// Postcondition: the quotient of the calling object (*this) / r2 is returned

	bool operator>(const rational &r2) const;
	// Postcondition: return true if *this is greater than r2; false otherwise

private:
	int num;	// numerator
	int denom;	// denominator

	rational gcd();
	// "helper" function intentionally hidden from outside of class; used to reduce a rational number to a simpler form; e.g., 2/4 ' 1/2.
	// Postcondition: return the greatest common divisor between num and denom
};

istream& operator>>(istream & in, rational &robj)
{
cout << "Enter a rational number" << endl;
cout << "Enter the numerator: ";
cin >> robj.num;
cout << "Enter the denominator: ";
cin >> robj.denom;
robj.gcd();
return in;
}

ostream& operator<<(ostream & out, rational &robj)
{
cout << robj.num << " / " << robj.denom;
return out;
}

rational::rational(int n, int d)
{
num = n;
denom = d;
}
  
rational rational::operator+(const rational &r2) const
{
int n = num * r2.denom + denom * r2.num;
int d = denom * r2.denom;
return rational(n, d);
}

rational rational::operator-(const rational &r2) const
{
int n = num * r2.denom - denom * r2.num;
int d = denom * r2.denom;
return rational(n, d);
}

rational rational::operator*(const rational &r2) const
{
int n = num * r2.num;
int d = denom * r2.denom;
return rational(n, d);
}

rational rational::operator/(const rational &r2) const
{
int n = num * r2.denom;
int d = denom * r2.num;
return rational(n, d);
}

bool rational::operator>(const rational &r2) const
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
	bool h;
	rational a,b, op;
	cin >> a >> b;
	h = a > b;

	if (h == 1)
	{
 	cout << a <<" >= " << b; //so much easier
	}
	else
	{
 	cout << a <<" <=  " << b;
	}

	cout << "\nAddition: ";
	op = a + b;
	cout << op;
	cout << "\nSubtraction: ";
	op = a - b;
	cout << op;
	cout << "\nMultiplication: ";
	op = a * b;
	cout << op;
	cout << "\nDivision: ";
	op = a / b;
	cout << op;
	cout << endl;
	return 0;

}
