#include<iostream>
#include<cstring>
using namespace std;
int visit[1001]; // 행이 0으로시작하는지 x로시작하는지 알려주는 값
int map[1001][1001];
int main()
{
	// row 인덱스를 셋팅하면서 00xx00xx...순으로 표시한다.
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		int a = 2; // 인덱스값인데 2번째기준
		int b = 3; // 인덱스값인데 3번째기준
		int cnt = 0;
		int n, m;
		int ret = 0;
		cin >> m >> n;
		for (int i = 0; i < n; i++)
		{
			if (i == a || i == b)
			{
				visit[i] = 1; // x인것은 1로표시
				cnt++;
				if (cnt == 2)
				{
					cnt = 0;
					a += 4;
					b += 4;
				}
			}
		}
		// 행 기준값 셋팅 완료
		for (int i = 0; i < n; i++)
		{
			//row에 따라 시작값 셋팅
			cnt = 0;
			if (visit[i] == 0)
			{
				a = 2;
				b = 3;
			}
			else if (visit[i] == 1) //visit= 1이 x부터시작인곳
			{
				a = 0;
				b = 1;
			}

			for (int j = 0; j < m; j++)
			{
				if (j == a || j == b)
				{
					map[i][j] = 1; // x인곳 1로표시한다.
					cnt++;
					if (cnt == 2)
					{
						a += 4;
						b += 4;
						cnt = 0;
					}
				}
			}
		}
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d", map[i][j]);
			}
			puts("");
		}*/
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 0)
					ret++;
			}
		}
		printf("#%d %d\n", t, ret);
		memset(map, 0, sizeof(map));
	}
}