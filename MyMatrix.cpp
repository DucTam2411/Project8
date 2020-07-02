#include "MyMatrix.h"

MyMatrix::MyMatrix(int mx, int nx)
{
	m = mx;
	n = nx;
	a = new double* [m];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
}

void MyMatrix::nhap()
{
	cout << "Enter m: "; cin >> m;
	cout << "Enter n: "; cin >> n;
	a = new double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new double[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	
}

void MyMatrix::nhapFile(ifstream &Fin)
{
	Fin >> m;
	Fin >> n;
	a = new double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new double[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			Fin >> a[i][j];
	}
}

void MyMatrix::xuat()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

MyMatrix MyMatrix::operator+(MyMatrix b)
{
	if (m != b.m || n != b.n) {
		return *this;
	}
	MyMatrix tem(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tem.a[i][j] = a[i][j] + b.a[i][j];
		}
	}
	return tem;
}
MyMatrix MyMatrix::operator-(MyMatrix b) {
	if (m != b.m || n != b.n) {
		return *this;
	}
	MyMatrix tem(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tem.a[i][j] = a[i][j] - b.a[i][j];
		}
	}
	return tem;
}

MyMatrix MyMatrix::operator*(MyMatrix b)
{
	if(n != b.m) {
		return	*this;
	}
	MyMatrix tem(m, b.n);
	int res = 0;
	int g = 0, k = 0;
	int  cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < b.n; j++) {
			for (int k = 0; k < n; k++) {
				tem.a[i][j] += a[i][k] * b.a[k][j];
			}
		}
	}
	return tem;
}

istream& operator>>(istream& is, MyMatrix& a)
{
	is >> a.m;
	is>> a.n;
	a.a = new double* [a.m];
	for (int i = 0; i < a.m; i++) {
		a.a[i] = new double[a.n];
	}
	for (int i = 0; i < a.m; i++) {
		for (int j = 0; j < a.n; j++)
			is>> a.a[i][j];
	}
	return is;
}

ostream& operator<<(ostream& os, MyMatrix b)
{
	for (int i = 0; i < b.m; i++) {
		for (int j = 0; j < b.n; j++) {
			os << b.a[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}
