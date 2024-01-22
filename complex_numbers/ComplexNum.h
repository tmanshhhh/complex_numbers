#include <iostream>

class ComplexNumbers {
private:
	double real;
	double imaginary;

public:
	ComplexNumbers(double real, double imaginary) : real(real), imaginary(imaginary) {}

	double getRealPart();
	double getImaginaryPart();

	void setRealPart(double number);
	void setImaginaryPart(double number);

	ComplexNumbers operator+(const ComplexNumbers& other);
	ComplexNumbers operator-(const ComplexNumbers& other);
	ComplexNumbers operator*(const ComplexNumbers& other);
	ComplexNumbers operator/(const ComplexNumbers& other);

	bool operator==(const ComplexNumbers& other);
	bool operator!=(const ComplexNumbers& other);

	bool operator==(double number);
	bool operator!=(double number);

	ComplexNumbers comp_exp(int exp);

	double comp_module();

	void show();
};
