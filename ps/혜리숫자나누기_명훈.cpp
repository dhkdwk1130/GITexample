#include<cstdio>
#include<iostream>
using namespace std;
int a[300000];
int N;
int M;

void solve(int t)
{
	int before = 0;
	int mod = 0;
	int ret = 1;
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		mod = (10 * before) + a[i];
		mod = mod % M;
		if (mod == 0)
		{
			cnt++;
			if (i == N - 1)
				flag = true;
		}
		before = mod;
	}
	if (!flag)
	{
		printf("#%d 0\n", t);
		return;
	}
	else
	{
		cnt--;
		for (int i = 0; i < cnt; i++)
		{
			ret = (ret * 2) % 1000000007;
		}
		printf("#%d %d\n", t, ret);
	}
}
int main()
{
	int T;
	scanf("%d\n", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			scanf("%1d", &a[i]);
		}
		solve(i); 
	}
	return 0;
}