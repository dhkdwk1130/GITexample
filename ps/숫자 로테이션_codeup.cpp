#include<stdio.h>
int main()
{
	int arr[1999];
	int k;
	int j = 0;
	scanf("%d",&k);
	for(int i= 0; i<k; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i = k; i<(2*k)-1; i++)
	{
		arr[i] = arr[j];
		j++;
	}
	for(int i = 0; i<k; i++)
	{
		for(j= i; j<k+i; j++)
		{
			printf("%d ",arr[j]);
		}
		puts("");
	}
}
