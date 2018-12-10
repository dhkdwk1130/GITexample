#include<stdio.h>
int money[1000001];
int main() {
	int n;
	int T;
	long long int sum = 0;
	int target; // 현재 최대 매매가,기준수치
	scanf("%d", &T);
	for(int t= 1; t<= T; t++)
	{ 
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &money[i]);
		}
		target = n - 1;
		for (int i = n - 2; i >= 0; i--)
		{
			if (money[i] <= money[target])
			{
				sum = sum + (money[target] - money[i]);
			}
			else
			{
				target = i;
			}
		}
		printf("#%d %lld\n",t, sum);
	}
}