#include<iostream>
#include<cmath>
using namespace std;
int arr[1001] = { 0, };
int main()
{
	int num;
	int T;
	int cnt = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &num);
		arr[num] = num;
	}
	for (int i = 2; i <= sqrt(1000); i++)
	{
		for (int j = i + i; j <= 1000; j = j + i)
		{
			if (!arr[j]) continue;
			arr[j] = 0;
		}
	}
	for (int i = 2; i <= 1000; i++)
	{
		if (i == 1) continue;
		if (arr[i])
		{
			cnt++;
		}
	}
	printf("%d\n", cnt);
}