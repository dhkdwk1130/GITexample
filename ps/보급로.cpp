#include<iostream>
int gray[101][101];
int map[101][101];
int n;
int min;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
bool isInMap(int x, int y)
{
	if (x < 1 || y>n || x > n || y < 1)
	{
		return false;
	}
	else
		return true;
}
void solve(int x, int y, int t)
{
	if (x == n && y == n)
	{
		if (min > t)
		{
			min = t;
		}
		return;
	}
	if (min < t)
		return;
	else
	{
		int cx;
		int cy;
		gray[x][y] = 1;
		for (int i = 0; i < 4; i++)
		{
			cx = x + dx[i];
			cy = y + dy[i];
			if (isInMap(cx, cy))
			{
				if (!gray[cx][cy])
				{
					solve(cx, cy, map[cx][cy] + t);
					gray[cx][cy] = 0;
				}
				continue;
			}
			else
				continue;
		}
	}
}

int main()
{
	int test_case;
	scanf("%d", &test_case);
	for (int i = 1; i <= test_case; i++)
	{
		scanf("%d", &n);
		min = 100000000;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}
		solve(1, 1, 0);
		printf("%d\n", min);
	}	
}