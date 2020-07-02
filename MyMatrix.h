#pragma once
#include<iostream>
#include <fstream>

using namespace std;

class MyMatrix
{
	double** a;
	int m, n;
public:
	MyMatrix(){}
	MyMatrix(int m, int n);
	void nhap();
	void nhapFile(ifstream &Fin);
	void xuat();
	friend istream& operator >> (istream& is, MyMatrix &a);
	friend ostream& operator << (ostream& os, MyMatrix);
	MyMatrix operator + (MyMatrix b);
	MyMatrix operator - (MyMatrix b);
	MyMatrix operator * (MyMatrix b);
};

