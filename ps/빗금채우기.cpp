#include<iostream>
using namespace std;
int map[101][101];
int main()
{
	int n, m,k, j,j2;
	bool flag = true;
	int number = 1;
	scanf("%d %d", &n, &m);
	//행첫번째 요소 기준으로 범위내에 있는 값을 출력한다.
	for (int i = 0; i < n; i++)
	{
		k = i;
		j = 0;
		flag = true;
		while (flag)
		{
			if (k < 0 || j >= m)
			{
				flag = false;
				continue;
			}
			map[k][j] = number++;
			k--;
			j++;
		}
	}
	for (int j = 1; j < m; j++)
	{
		// j는 열요소 기준값
		j2 = j;
		k = n - 1;
		while (1)
		{
			if (j2 >= m || k < 0)
			{
				break;
			}
			map[k][j2] = number++;
			k--;
			j2++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}