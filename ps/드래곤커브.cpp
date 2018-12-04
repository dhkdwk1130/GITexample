#include<iostream>
#include<vector>
#define left 2
#define right 0
#define up 1
#define down 3

using namespace std;
vector<int> v;// �̵����û��׵�
int visit[101][101];
int dx[] = { 0, -1,0,1 }; // 0 right 1 up 2 left 3 down 
int dy[] = { 1, 0,-1,0 };
int main()
{
	int count = 0;
	int N;
	int x, y, d, g;//x�� �ʿ��� �����, y�� �ʿ��� ����
	scanf("%d", &N);
	while (N--)
	{
		int endx, endy; //����ǥ
		scanf("%d %d %d %d", &y, &x, &d, &g); // x, y��ǥ�� �ʿ� �°� ����Ҽ� ����
											  //0���� �׸���
		endx = x;
		endy = y;
		visit[x][y] = 1;
		endx += dx[d];
		endy += dy[d];
		visit[endx][endy] = 1;
		v.push_back(d); // vector�� ���� ���� �׸��� ���� ���� ����
		while (g--)
		{
			int vsize = v.size();
			for (int i = vsize - 1; i >= 0; i--) // v����� ���������� ó������ ����
			{
				int nd = (v[i] + 1) % 4;
				endx += dx[nd];
				endy += dy[nd];
				visit[endx][endy] = 1;
				v.push_back(nd);
			}
		}
		v.clear();
	}
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (visit[i][j] == 1 && visit[i + 1][j] == 1 && visit[i][j + 1] == 1 && visit[i + 1][j + 1] == 1)
				count++;
		}
	}
	printf("%d", count);

}