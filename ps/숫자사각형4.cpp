#include<stdio.h>
void Solve1(int n)
{
	// ����1
	// ���ȣ�� n�� ���
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			printf("%d ",i);
		}
		printf("\n");	
	} 
}
void Solve2(int n)
{
	//����2
	for(int i = 1; i<=n; i++)
	{
		if(i%2 == 0)
		{
			for(int j = n; j>=1; j--)
			{
				printf("%d ",j);
			}
		}
		else
		{
			for(int j = 1; j<=n; j++)
			{
				printf("%d ",j);
			}
		}
		printf("\n");
	} 
}
void Solve3(int n)
{
	//����3
	int k;
	for(int i = 1; i<=n; i++)
	{
		k = i;
		for(int j = 1; j<=n; j++)
		{
			printf("%d ",k);
			k = k+i;
		}	
		printf("\n");
	} 
}
int main()
{
	int n,m; 
	scanf("%d %d",&n,&m);
	//m���������� �Լ� ���
	if(m == 1)
	{
		Solve1(n);	
	}
	else if(m==2)
	{
		Solve2(n);
	}
	else
	{
		Solve3(n);	
	} 
}
