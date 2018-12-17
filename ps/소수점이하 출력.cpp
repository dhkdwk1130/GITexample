#include<iostream>
using namespace std;
unsigned long long ten;
int main()
{
	double num;
	int a, b,c;
	cin >> a >> b;
	num = (double)a / b;
	c = a / b;
	ten = 10000000000;
	num = (num - c) * ten;
	printf("%010.lf", num-0.5);
}