#include<iostream>
using namespace std;
int d[501][501];
int a[501][501];
int N;
int Max2 = -1;
int solve(int n, int x, int y)
{
	if(x==1 && y==1)
	{
		return a[1][1];
	}
	if(a[x][y] == -1)
	{
		return 0;
	}
	if(d[x][y]) return d[x][y];
	d[x][y] = max(solve(n-1,x-1,y), solve(n-1,x-1,y-1)) + a[x][y];
	return d[x][y];
}
int main()
{
	scanf("%d",&N);
	int Max;
	for(int i = 0; i<=N; i++)
	{
		for(int j = 0; j<=N; j++)
		{
			a[i][j] = -1;
		}
	}
	for(int i = 1; i<=N; i++)
	{
		for(int j = 1; j<=i; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i =1; i<=N; i++)
	{
		Max = solve(N,N,i);
		if(Max > Max2)
		{
			Max2 = Max;
		}
	}
	printf("%d",Max2);
}

//정수삼각형 for문 dp버전 
//#include<iostream>
//using namespace std;
//int d[501][501];
//int a[501][501];
//int main()
//{
//	int n,m = -1;
//	scanf("%d",&n);
//	for(int i = 0 ;i <n; i++)
//	{
//		for(int j = 0; j<=i; j++)
//		{
//			scanf("%d",&a[i][j]);
//		}
//	}
//	d[0][0] = a[0][0];
//	for(int i = 1; i<n; i++)
//	{
//		for(int j = 0; j<=i; j++)
//		{
//			if(j == 0)
//			{
//				d[i][j] = d[i-1][0] + a[i][0];
//				continue;
//			}
//			if(i == j)
//			{
//				d[i][j] = d[i-1][j-1] + a[i][j];
//			}
//			else
//			{
//				d[i][j] = max(d[i-1][j], d[i-1][j-1]) + a[i][j];
//			}
//		}
//	}
//	for(int i = 0; i<n; i++)
//	{
//		if(m < d[n-1][i])
//		{
//			m = d[n-1][i];
//		}
//	}
//	printf("%d",m);
//}
