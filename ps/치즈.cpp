#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t_cnt; //�ð� ����
int c_cnt; //ġ�� ����
int r, l;
int map[101][101];
int visit[101][101];
int dx[] = { 1,-1,0,0 }; //0 �� 1 �� 2 �� 3 ��
int dy[] = { 0,0,-1,1 };
// �ѹ��� Ž���� ���������� ��üũ
bool mapcheck(int x, int y) // �� ���� �˻�
{
	if (x < r && x >= 0 && y < l && y >= 0)
		return true;  // �������� ������ ��
	else
		return false; // �������� ������ ����
}
void dfs(int r, int l) // dfs Ž��  (0,0) ����
{
	int tr, tl; // �̵��� ��ǥ dx,dy ���Ѱ�

	visit[r][l] = 1; // ���� ��ǥ �湮��ǥ��
	for (int i = 0; i < 4; i++)
	{
		tr = r + dx[i]; // ��, �� ,�� ,��� ���� �����ش�.
		tl = l + dy[i];
		if (!mapcheck(tr, tl)) // �����⸶�� �ʰ˻�
			continue;
		if (map[tr][tl] == 1) // �̵��� ��ǥ�� 1�̶�� 
		{
			map[tr][tl] = 0;    // �� ��ǥ�� 0 ���� �ٲ۴�. 
			visit[tr][tl] = 1; // �� ��ǥ�� �湮�ߴٷ� ǥ��
			c_cnt++; // ġ�� ������ �ϳ� �����Ѵ�.
		}
		if (map[tr][tl] == 0 && visit[tr][tl] != 1) // �̵��� ��ǥ�� 0�̶�� �׳� �̵��Ѵ�. ��, �湮�ȵ��־����
		{
			dfs(tr, tl); // �̵������� ��ǥ�� �ٽ� Ž�� ���� 
		}
	}
}
bool isclean()  // �ʿ� ġ� ���� ���������� Ȯ�� �Լ�
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (map[i][j] == 1)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	cin >> r >> l;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	while (!isclean())
	{
		c_cnt = 0;
		dfs(0, 0); //dfs ����
		memset(visit, 0, sizeof(visit)); // �湮���� �ʱ�ȭ 
		t_cnt++; // dfs�ѹ��Ҷ����� �ѽð������� 
	}
	cout << t_cnt << '\n' << c_cnt;
}