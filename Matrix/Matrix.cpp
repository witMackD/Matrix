// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Matrix {
public:
	Matrix(int rs, int cs);
	~Matrix();
	double &operator()(int r, int c);
	const double &operator () (int r, int c) const;
private:
	int rs, cs;
	double *d;
};

Matrix::Matrix(int rs, int cs) : rs(rs), cs(cs), d(new double[rs * cs]) {
std:cout << "Matrix(int, int)" << std::endl;
}

Matrix::~Matrix() {
std:cout << "DESTROY" << std::endl;
	delete[] d;
	d = nullptr;
}

double &Matrix::operator () (int r, int c) {
	return d[r*cs + c];
}

const double &Matrix::operator () (int r, int c) const {
	return d[r*cs + c];
}

int main()
{
	Matrix m1(2, 3);
	m1(1, 2) = 7;
	m1.~Matrix();
	std::cout << m1(1, 2) << std::endl;
}
