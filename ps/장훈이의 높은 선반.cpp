#include<iostream>
using namespace std;
int N;
int B; // 기준선반값 b>=인것중 최소값찾는다.
int min;  // 16에 가장 가까운값 
int h[21]; //20명에 대한 키정보
void solve(int now, int sum)
{
	//now가 주어진 n명에 도달했을때의 sum 값을 비교해서 min값을 갱신한다.
	if (now == N+1)
	{
		if (sum >= B)
		{
			if (min > sum)
				min = sum;
		}
		return;
	}
	//now번째 인원의 height값을 포함하는경우, 안하는경우에 대한 sum 값을 누적시킨다
	else
	{
		solve(now + 1, sum + h[now]); // 다음 인원의 키값을 더하여 있는경우
		solve(now + 1, sum); // 다음인원의 키값을 안더해서 없는경우
	}
	
}
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N >> B;
		min = 100000000; // min 초기화
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &h[i]);
		}
		solve(1, 0);
		printf("#%d %d\n", i, min - B);
	}
}