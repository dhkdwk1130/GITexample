#include<stdio.h>
int main()
{
	int d[100001]={0,};
	int num;
	int n,m,i,j;
	scanf("%d",&n);
	for(int i =1; i<=n; i++)
	{
		scanf("%d",&num);
		d[i] = d[i-1] + num;
	}	
	scanf("%d",&m);
	for(int k = 0; k< m; k++)
	{
		scanf("%d %d",&i,&j);
		printf("%d\n", d[j]-d[i-1]);
	}
} 
