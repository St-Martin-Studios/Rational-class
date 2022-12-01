

#include <iostream>

//Look at operator overloading in class briefly

class Exception {
public:
	Exception() { std::cout << "Throw exception here"; }


};

class Rational {

public:
	Rational(int numerator, int denominator) : numerator{ numerator }, denominator{denominator} {
		
		if (denominator == 0)
		{
			Exception();
		}

	}
	Rational() :numerator{ 1 }, denominator{1} {}

	const int get_num() const { return numerator; }
	const int get_den() const { return denominator; }

	void set_num(int num) { numerator = num; }
	void set_den(int den) { denominator = den; }

	Rational operator=(const Rational& r1) {
	
		numerator = r1.numerator;
		denominator = r1.denominator;

		return Rational(numerator, denominator);
	}

	static int find_LCM(int a, int b);

private:
	int numerator;
	int denominator;


};

double convert_double(const Rational& r1){
	return (double(r1.get_num()) / double(r1.get_den()));
}

int Rational::find_LCM(int a, int b) {

	int lcm{1};

	while (1) {
		if (lcm % a == 0 && lcm % b == 0) {
			return lcm;
			break;
		}
		lcm++;
	}

	return lcm;
}

Rational operator+(const Rational& r1, const Rational& r2) {
	Rational result;

	int Rational1Numerator = r1.get_num();
	int Rational2Numerator = r2.get_num();

	int Rational1Denominator = r1.get_den();
	int Rational2Denominator = r2.get_den();


	if (Rational1Denominator == Rational2Denominator)
	{
		result.set_num(Rational1Numerator + Rational2Numerator);
		result.set_den(Rational1Denominator);
	}
	else
	{

		int lcm = Rational::find_LCM(Rational1Denominator, Rational2Denominator);
		result.set_den(lcm);

		result.set_num((lcm / Rational1Denominator) * Rational1Numerator + (lcm / Rational2Denominator) * Rational2Numerator);
	}

	return result;
}

// + operator overloading with int
Rational operator+(const Rational& r1, int number) {

	Rational result;

	if (number == 0)
	{
		return r1;
	}
	else if(number > 0)
	{
		result.set_num(r1.get_num() + (number * r1.get_den()));
		result.set_den(r1.get_den());
	}

	return result;
}

Rational operator-(const Rational& r1, const Rational& r2) {
	Rational result;

	int Rational1Numerator = r1.get_num();
	int Rational2Numerator = r2.get_num();

	int Rational1Denominator = r1.get_den();
	int Rational2Denominator = r2.get_den();


	if (Rational1Denominator == Rational2Denominator)
	{
		result.set_num(Rational1Numerator - Rational2Numerator);
		result.set_den(Rational1Denominator);
	}
	else
	{

		int lcm = Rational::find_LCM(Rational1Denominator, Rational2Denominator);
		result.set_den(lcm);

		result.set_num((lcm / Rational1Denominator) * Rational1Numerator - (lcm / Rational2Denominator) * Rational2Numerator);
	}

	return result;
}

Rational operator*(const Rational& r1, const Rational& r2) {

	Rational result;

	if (r1.get_num() == 0 || r2.get_num() == 0)
	{
		result.set_num(0);
	}
	else
	{
		result.set_num(r1.get_num() * r2.get_num());
	}

	result.set_den(r1.get_den() * r2.get_den());


	return result;
}

Rational operator/(const Rational& r1, const Rational& r2) {

	Rational result;

	if (r1.get_num() == 0 || r2.get_num() == 0)
	{
		Exception();
	}
	else
	{
		result.set_num(r1.get_num() * r2.get_den());
	}

	result.set_den(r1.get_den() * r2.get_num());


	return result;
}

bool operator==(const Rational& r1, const Rational& r2) {

	return convert_double(r1) == convert_double(r2);
};

std::ostream& operator<<(std::ostream& os, const Rational& Number) {

	os << Number.get_num() << "/" << Number.get_den();

	return os;
}


int main()
{

	Rational a(12, 4);
	Rational b(6, 2);


	Rational r1(2, 3);

	std::cout << a / b << std::endl;

	std::cout << (r1 + 5) << std::endl;


	std::cout << convert_double(b) << std::endl;

	std::string result = a == b ? "yes" : "no";
	std::cout << "Is a equal to b: " + result;

}

