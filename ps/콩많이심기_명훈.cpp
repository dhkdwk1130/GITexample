#include<iostream>
#include<cstring>
using namespace std;
int visit[1001]; // ���� 0���ν����ϴ��� x�ν����ϴ��� �˷��ִ� ��
int map[1001][1001];
int main()
{
	// row �ε����� �����ϸ鼭 00xx00xx...������ ǥ���Ѵ�.
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		int a = 2; // �ε������ε� 2��°����
		int b = 3; // �ε������ε� 3��°����
		int cnt = 0;
		int n, m;
		int ret = 0;
		cin >> m >> n;
		for (int i = 0; i < n; i++)
		{
			if (i == a || i == b)
			{
				visit[i] = 1; // x�ΰ��� 1��ǥ��
				cnt++;
				if (cnt == 2)
				{
					cnt = 0;
					a += 4;
					b += 4;
				}
			}
		}
		// �� ���ذ� ���� �Ϸ�
		for (int i = 0; i < n; i++)
		{
			//row�� ���� ���۰� ����
			cnt = 0;
			if (visit[i] == 0)
			{
				a = 2;
				b = 3;
			}
			else if (visit[i] == 1) //visit= 1�� x���ͽ����ΰ�
			{
				a = 0;
				b = 1;
			}

			for (int j = 0; j < m; j++)
			{
				if (j == a || j == b)
				{
					map[i][j] = 1; // x�ΰ� 1��ǥ���Ѵ�.
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