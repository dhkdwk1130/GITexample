//baekjoon judge problem 1193
#include<stdio.h>
int main()
{
	int x;
	int dx,dy;
	int i=1;
	int sum = 0;
	scanf("%d",&x);
	while(sum < x) // find base condition 
	{
		sum += i;
		i++;
	}
	i--;
	sum = sum-i;
	dx = i;
	dy = 1;
	if(i % 2 == 0)
	{
		dx = 1;
		dy = i;
		sum = x - sum;
		dx = dx + (sum-1);
		dy = dy - (sum-1);
		printf("%d/%d\n",dx,dy);		
	}
	else
	{
		sum = x-sum;
		dx= dx - (sum-1);
		dy = dy + (sum-1);
		printf("%d/%d\n",dx,dy);		
	}	
}
