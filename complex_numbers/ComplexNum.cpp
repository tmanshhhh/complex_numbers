#include "ComplexNum.h"
#include <cmath>

double ComplexNumbers::getRealPart() {
	return real;
}

double ComplexNumbers::getImaginaryPart() {
	return imaginary;
}

void ComplexNumbers::setRealPart(double number) {
	real = number;
}

void ComplexNumbers::setImaginaryPart(double number) {
	imaginary = number;
}

ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& other) {
	double real_sum = real + other.real;
	double im_sum = imaginary + other.imaginary;

	return ComplexNumbers(real_sum, im_sum);
}

ComplexNumbers ComplexNumbers::operator-(const ComplexNumbers& other) {
	double real_dif = real - other.real;
	double im_dif = imaginary - other.imaginary;

	return ComplexNumbers(real_dif, im_dif);
}

ComplexNumbers ComplexNumbers::operator*(const ComplexNumbers& other) {
	double real_multipli = (real * other.real) - (imaginary * other.imaginary);
	double im_multipli = (imaginary * other.real) + (real * other.imaginary);

	return ComplexNumbers(real_multipli, im_multipli);
}

ComplexNumbers ComplexNumbers::operator/(const ComplexNumbers& other) {
	double real_division = ((real * other.real) + (imaginary * other.imaginary)) / ((other.real * other.real) + (other.imaginary * other.imaginary));
	double im_division = (imaginary * other.real - real * other.imaginary) / ((other.real * other.real) + (other.imaginary * other.imaginary));

	return ComplexNumbers(real_division, im_division);
}

bool ComplexNumbers::operator==(const ComplexNumbers& other) {
	return (fabs(real - other.real) < 1e-7 && fabs(imaginary - other.imaginary) < 1e-7);
}

bool ComplexNumbers::operator!=(const ComplexNumbers& other) {
	return !(fabs(real - other.real) < 1e-7 && fabs(imaginary - other.imaginary) < 1e-7);
}

bool ComplexNumbers::operator==(double number) {
	return (fabs(real - number) < 1e-7);
}

bool ComplexNumbers::operator!=(double number) {
	return !(fabs(real - number) < 1e-7);
}

ComplexNumbers ComplexNumbers::comp_exp(int exp) {
	double modul = sqrt(pow(real, 2) + pow(imaginary, 2));
	double arg = atan(imaginary / real);
	double real_pow = pow(modul, exp) * cos(exp * arg);
	double im_pow = pow(modul, exp) * sin(exp * arg);

	return ComplexNumbers(real_pow, im_pow);
}

double ComplexNumbers::comp_module() {
	return sqrt((real * real) + (imaginary * imaginary));
}

void ComplexNumbers::show() {
	std::cout << real << (imaginary < 0 ? "-" : "+") << abs(imaginary) << "i" << std::endl;
}
