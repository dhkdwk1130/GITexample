#include<iostream>
using namespace std;
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a / b > 0) a = a % b;
	for (int i = 0; i < 10; i++)
	{
		a = a * 10;
		printf("%d", a / b);
		a = a % b;
	}
}