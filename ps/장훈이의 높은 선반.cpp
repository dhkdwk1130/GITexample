#include<iostream>
using namespace std;
int N;
int B; // ���ؼ��ݰ� b>=�ΰ��� �ּҰ�ã�´�.
int min;  // 16�� ���� ���� 
int h[21]; //20�� ���� Ű����
void solve(int now, int sum)
{
	//now�� �־��� n�� ������������ sum ���� ���ؼ� min���� �����Ѵ�.
	if (now == N+1)
	{
		if (sum >= B)
		{
			if (min > sum)
				min = sum;
		}
		return;
	}
	//now��° �ο��� height���� �����ϴ°��, ���ϴ°�쿡 ���� sum ���� ������Ų��
	else
	{
		solve(now + 1, sum + h[now]); // ���� �ο��� Ű���� ���Ͽ� �ִ°��
		solve(now + 1, sum); // �����ο��� Ű���� �ȴ��ؼ� ���°��
	}
	
}
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N >> B;
		min = 100000000; // min �ʱ�ȭ
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &h[i]);
		}
		solve(1, 0);
		printf("#%d %d\n", i, min - B);
	}
}