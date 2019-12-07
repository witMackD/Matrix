// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


class Matrix {
public:
	Matrix(int rs, int cs);
	const double &operator () (int r, int c) const;
private:
	int rs, cs;
	double *d;
};

Matrix::Matrix(int rs, int cs) : rs(rs), cs(cs), d(new double[rs * cs]) {
std:cout << "Matrix(int, int)" << std::endl;
}

double &Matrix::operator () (int r, int c) {
	return d[r*cs+c];
}



int main()
{
	Matrix m1(2, 3);
	m1(1, 2) = 7;
	std::cout << m1(1, 2);
    std::cout << "Hello World!\n"; 
}
