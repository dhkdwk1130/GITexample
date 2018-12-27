#include<stdio.h>
int main()
{
	long long int gcd,a,b, q, p, r=1;
	long long int lcm;
	scanf("%lld %lld", &q, &p);
	a = q;
	b = p;
	while (r != 0)
	{
		r = p % q;
		p = q;
		q = r;
	}
	lcm = (a*b) / p;
	printf("gcd : %d\n", p);
	printf("lcm : %d\n", lcm);
}