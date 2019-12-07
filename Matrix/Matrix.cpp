// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Matrix {
public:
	Matrix(int rs, int cs);
	Matrix();
	Matrix(const Matrix &m);
	~Matrix();
	double &operator()(int r, int c);
	Matrix &operator = (const Matrix &m);
	const double &operator () (int r, int c) const;
private:
	int rs, cs;
	double *d;
};

Matrix::Matrix(int rs, int cs) : rs(rs), cs(cs), d(new double[rs * cs]) {
	std:cout << "Matrix(int, int)" << std::endl;
}

Matrix::Matrix(): rs(), cs(), d()
{
	std:cout << "Matrix()" << std::endl;
}

Matrix::Matrix(const Matrix & m) : rs(m.rs), cs(m.cs), d(m.d)
{
std:cout << "Matrix(const Matrix &)" << std::endl;
	for (int i = 0; i < rs*cs; ++i) {
		d[i] = m.d[i];
	}

}

Matrix::~Matrix() {
std:cout << "DESTROY" << std::endl;
	delete[] d;
	d = nullptr;
}

double &Matrix::operator () (int r, int c) {
	return d[r*cs + c];
}

Matrix &Matrix::operator=(const Matrix & m)
{
	rs = m.rs;
	cs = m.cs;
	d = new double[rs*cs];
	for (int i = 0; i < rs * cs; i++) {
		d[i] = m.d[i];
	}
	return *this;
}

const double &Matrix::operator () (int r, int c) const {
	return d[r*cs + c];
}

int main()
{
	Matrix m1(2, 3);
	Matrix m2 = m1;
	m1(1, 2) = 7;
	std::cout << m1(1, 2) << std::endl;
}
