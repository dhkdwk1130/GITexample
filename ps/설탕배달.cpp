#include<iostream>
using namespace std;
int main() {
	int a, b;
	int gcd;
	int lcm;
	int mod;
	int a1;
	int b1;
	cin >> a >> b;
	a1 = a;
	b1 = b;
	while (a%b != 0)
	{
		mod = a % b;
		a = b;
		b = mod;
	}
	gcd = b;
	lcm = (a1*b1) / gcd;
	cout << gcd << '\n' << lcm;
	printf("\n");
}