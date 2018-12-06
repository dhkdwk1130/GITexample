#include<stdio.h>
int map[100][100]; // 4각형정보
void solve(int startX, int startY, int endX, int endY)
{
	startX = startX + 1;
	startY = startY + 1;
	for (int i = startX; i <= endX; i++)
	{
		for (int j = startY; j <= endY; j++)
		{
			if(!map[i][j])
			map[i][j] = 1;
		}
	}
}
int main()
{
	int ret = 0;
	int x1, x2, x3, x4, x5, x6, x7, x8;
	int y1, y2, y3, y4, y5, y6, y7, y8;
	
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
	scanf("%d %d %d %d", &x5, &y5, &x6, &y6);
	scanf("%d %d %d %d", &x7, &y7, &x8, &y8);
	solve(x1, y1, x2, y2);
	solve(x3, y3, x4, y4);
	solve(x5, y5, x6, y6);
	solve(x7, y7, x8, y8);
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1)
				ret++;
		}
	}
	printf("%d\n", ret);
}