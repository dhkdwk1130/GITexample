#include<stdio.h>
int main()
{
	int lcd, q, p, r;
	scanf("%d %d", &q, &p);
	while (r != 0)
	{
		r = p % q;
		p = q;
		q = r;
	}
	printf("lcd : %d", q);
}