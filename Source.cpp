#include<iostream>
#include "MyMatrix.h"
using namespace std;
ifstream Fin("E:/C++/OOP/Submision/test.txt");
int main() {
	MyMatrix a, b;
	a.nhapFile(Fin);
	b.nhapFile(Fin);
	MyMatrix c = a * b;
	c.xuat();
}