#include<stdio.h>
int rgb[1001][3];
int Min = 987654321;
int d[1001][3];
int min(int x, int y) { return x<y ? x : y; }
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j<3; j++)
			scanf("%d", &rgb[i][j]);
	}
	d[1][0] = rgb[1][0];
	d[1][1] = rgb[1][1];
	d[1][2] = rgb[1][2];
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + rgb[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + rgb[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + rgb[i][2];
	}
	for (int i = 0; i<3; i++)
	{
		if (d[n][i] < Min)
		{
			Min = d[n][i];
		}
	}
	printf("%d", Min);
}
