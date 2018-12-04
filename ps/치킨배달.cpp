#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int ans = 987654321; // ������ ġŲ�Ÿ�
int M;
int visit[13];
vector<pair<int, int>> home; // ����ǥ
vector<pair<int, int>> chicken; // ġŲ ��ǥ
int csize;
int min(int a, int b) { return a < b ? a : b; }
void solve(int inow, int cnt_now)
{
	// m�� ��� ��츦 ����ؼ� cnt_now�� M�� �Ǵ� ���� ġŲ �Ÿ��� �յ��� ���ؼ�
	// �ּҰ��� ���ϴ� �Լ�
	if (inow > csize) return; // �����ε����� ġŲ ������ �Ѿ�� ����
	if (cnt_now == M) // �ִ� M���� ����
	{
		int d; // ���������� �Ÿ�
		int x1, x2;
		int y1, y2;
		int tmp = 0;
		int homesize = home.size();
		for (int i = 0; i < homesize; i++)
		{
			int minnum = 987654321;
			for (int j = 0; j < csize; j++)
			{
				if (visit[j]) // ���õ� ġŲ���� �Ÿ��� ����ϰ� ������ �ּҰ��� ã�´�.
				{
					d = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
					if (minnum > d)
						minnum = d;
				}
			}
			tmp += minnum;
			
		}
		ans = min(ans, tmp); //����ġŲ�Ÿ� ����
		return;
	}
	// ���� ġŲ���� �����ϴ� ���� �ƴѰ�� ����
	visit[inow] = 1;// ���� ġŲ�� ����
	solve(inow + 1, cnt_now + 1); // ���� ġŲ�� ���� ���������Ƿ� inow + 1�Ѵ�.
	visit[inow] = 0; // �ٸ� ��츦 �ؾ��ϱ⿡ ���õ� ġŲ�� ����
	solve(inow + 1, cnt_now);
}
int main()
{
	int N;
	int num;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &num);
			if (num == 1)
			{
				home.push_back({ i,j });
			}
			else if (num == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}
	csize = chicken.size();
	solve(0, 0);
	printf("%d\n",ans);
}