#include<stdio.h>
int main()
{
	int map[101][101];
	int number = 1;
	int n;
	bool w = false; //false�� �ε��� ���ҹ���, true�� �ε��� ��������
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		if(w == false)
		{
			for(int j = n; j>=1; j--)
			{
				map[i][j] = number++;
			}
			w = true;
		}
		else
		{
			for(int j = 1; j<=n; j++)
			{
				map[i][j] = number++;
			}
			w=  false;
		}
	}
	for(int i= 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			printf("%d ",map[i][j]);
		}
		puts("");
	}
	return 0;
}
