#include<iostream>

long long max_margin = 0;
int cost[1000001];
bool flag(int a, int b)
{
	return a > b ? true : false;
}
using namespace std;
int main()
{
	int test_case;
	
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		max_margin = 0;
		int max_price;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &cost[i]);
		}
		max_price = cost[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			if (max_price > cost[i])
			{
				max_margin += max_price - cost[i];
			}
			else
			{
				max_price = cost[i];
			}
		}
		printf("#%d %lld\n", t, max_margin);
	}
}