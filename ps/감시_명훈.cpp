#include<iostream>
#include<vector>
using namespace std;
struct CCTV
{
	int x;
	int y;
	int type;
};
int map[9][9]; // �ִ� 8*8
int n, m;
int cnt_cctv;
int visit[9][9]; // �湮 ǥ�ø�
int size_cctv;
int cnt_max = -1;
vector < CCTV > type_cctv; // cctv ���� �ֱ�
vector <pair<int, int> > info_visit; // �湮�� ��ǥ�� ����
int visiting(CCTV cctv, int d) 
{
	// cctv������ 90�� ���⿡ ���� ���� �湮���ְ� ��� �湮�ߴ��� �������� �Լ�
	// type= ���� cctv����, d= 90�� ȸ�������� ����
	int type = cctv.type;
	int x = cctv.x;
	int y = cctv.y;
	int cnt = 0;
	if ( type == 1)
	{ 
		if(d == 0) 
		{ // ���������ΰ��
			for (int i = y+1; i < m; i++)
			{
				if (map[x][i] != 0)
				{
					if(map[x][i] == 6)
						break;
					else
					{
						continue;
					}
				}
				if (visit[x][i] != 1)
				{
					visit[x][i] = 1;
					info_visit.push_back(make_pair(x, i)); // �湮�� ��ǥ input
					cnt++;
				}
			}
		}
		else if(d == 1)
		{ // �Ʒ������ΰ��
			for (int i = x+1; i < n; i++)
			{
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
						break;
					else
					{
						continue;
					}
				}
				if (visit[i][y] != 1)
				{
					visit[i][y] = 1;
					info_visit.push_back(make_pair(i, y));
					cnt++;
				}
			}
		}
		else if (d == 2)
		{ //���ʹ����� ���
			for (int i = y - 1; i >= 0; i--)
			{
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
					{
						break;
					}
					else
						continue;
				}
				if (visit[x][i] != 1)
				{
					visit[x][i] = 1;
					info_visit.push_back(make_pair(x, i));
					cnt++;
				}
			}
		}
		else if (d == 3)
		{ //���ʹ����� ���
			for (int i = x-1; i >= 0; i--)
			{
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
					{
						break;
					}
					else
					{
						continue;
					}
				}
				if (visit[i][y] != 1)
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
		}
	}
	else if (type == 2)
	{ 
		if (d == 0)
		{//������ �湮ǥ��
			for (int i = y + 1; i < m; i++)
			{
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
			for (int i = y - 1; i >= 0; i--)
			{ // ���ʰ��°��
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back(make_pair(x, i));
					cnt++;
				}
			}
		}
		else if (d == 1)
		{ // ������ �湮ǥ��
			for(int i = x-1; i>=0; i--)
			{ // ���� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
						break;
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
			for (int i = x + 1; i < n; i++)
			{ // �Ʒ��� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
					{
						break;
					}
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
		}
	}
	else if (type == 3)
	{
		if (d == 0)
		{// �����ʹ���
			for (int i = x - 1; i >= 0; i--)
			{ // ���� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
						break;
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}

			}
			for (int i = y + 1; i < m; i++)
			{// ������ ���°��
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
		}
		else if (d == 1)
		{// 90��ȸ���ؼ� �Ʒ����� (����+�Ʒ�)
			for (int i = y + 1; i < m; i++)
			{// ������ ���°��
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
			for (int i = x + 1; i < n; i++)
			{ // �Ʒ��� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
					{
						break;
					}
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
		}
		else if (d == 2)
		{ // ���ʰ��¹��� (�Ʒ�+��)
			for (int i = x + 1; i < n; i++)
			{ // �Ʒ��� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
					{
						break;
					}
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
			for (int i = y - 1; i >= 0; i--)
			{
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
		}
		else if (d == 3)
		{ // ȭ��ǥ ��+��
			for (int i = y - 1; i >= 0; i--)
			{
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
			for (int i = x - 1; i >= 0; i--)
			{ // ���� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
						break;
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
		}
	}
	else if (type == 4)
	{
		if (d == 0)
		{//��+��+����
			for (int i = y - 1; i >= 0; i--)
			{
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
			for (int i = x - 1; i >= 0; i--)
			{ // ���� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
						break;
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
			for (int i = y + 1; i < m; i++)
			{// ������ ���°��
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
		}
		else if (d == 1)
		{//��+����+�Ʒ�
			for (int i = x - 1; i >= 0; i--)
			{ // ���� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
						break;
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
			for (int i = y + 1; i < m; i++)
			{// ������ ���°��
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
			for (int i = x + 1; i < n; i++)
			{ // �Ʒ��� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
					{
						break;
					}
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
		}
		else if (d == 2)
		{//��+�Ʒ�+����
			for (int i = y - 1; i >= 0; i--)
			{
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
			for (int i = x + 1; i < n; i++)
			{ // �Ʒ��� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
					{
						break;
					}
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
			for (int i = y + 1; i < m; i++)
			{// ������ ���°��
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
		}
		else if (d == 3)
		{//��+��+�Ʒ�
			for (int i = y - 1; i >= 0; i--)
			{
				if (map[x][i] != 0)
				{
					if (map[x][i] == 6)
						break;
					else
						continue;
				}
				if (!visit[x][i])
				{
					visit[x][i] = 1;
					info_visit.push_back({ x,i });
					cnt++;
				}
			}
			for (int i = x + 1; i < n; i++)
			{ // �Ʒ��� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
					{
						break;
					}
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
			for (int i = x - 1; i >= 0; i--)
			{ // ���� ���·���
				if (map[i][y] != 0)
				{
					if (map[i][y] == 6)
						break;
					else
						continue;
				}
				if (!visit[i][y])
				{
					visit[i][y] = 1;
					info_visit.push_back({ i,y });
					cnt++;
				}
			}
		}
	}
	else if (type == 5)
	{
		for (int i = y - 1; i >= 0; i--)
		{
			if (map[x][i] != 0)
			{
				if (map[x][i] == 6)
					break;
				else
					continue;
			}
			if (!visit[x][i])
			{
				visit[x][i] = 1;
				info_visit.push_back({ x,i });
				cnt++;
			}
		}
		for (int i = x + 1; i < n; i++)
		{ // �Ʒ��� ���·���
			if (map[i][y] != 0)
			{
				if (map[i][y] == 6)
				{
					break;
				}
				else
					continue;
			}
			if (!visit[i][y])
			{
				visit[i][y] = 1;
				info_visit.push_back({ i,y });
				cnt++;
			}
		}
		for (int i = x - 1; i >= 0; i--)
		{ // ���� ���·���
			if (map[i][y] != 0)
			{
				if (map[i][y] == 6)
					break;
				else
					continue;
			}
			if (!visit[i][y])
			{
				visit[i][y] = 1;
				info_visit.push_back({ i,y });
				cnt++;
			}
		}
		for (int i = y + 1; i < m; i++)
		{// ������ ���°��
			if (map[x][i] != 0)
			{
				if (map[x][i] == 6)
					break;
				else
					continue;
			}
			if (!visit[x][i])
			{
				visit[x][i] = 1;
				info_visit.push_back({ x,i });
				cnt++;
			}
		}
	}
	return cnt;
}

void solve(int cnt_check, int pos, int cnt_visit)
{
	// pos��ġ�� �ִ� cctv ������ ���� �� ������ 90�� �������� ��츦 �ʿ� �湮ǥ�����ִ� �Լ�
	// pos+1 ��ġ�� �Ѱ��ً��� cnt_check�� �ϳ� �����ش�(�Ѱ���cctv�� Ȯ�������� �˸�������)
	if (cnt_check == size_cctv)
	{
		// ���� Ȯ�εȰ����� �� cctv������� ��
		if (cnt_visit > cnt_max)
		{
			cnt_max = cnt_visit;
		}
		return;
	}
	else
	{
		int size_visit = 0;
		int cnt = 0;
		int k = 0;
		if (type_cctv[pos].type == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i�� 90�� ȸ������ ���ܳ��� ��� ����
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
			    for(int i =0; i<cnt; i++)
				{
					//size ��ŭ pop���ش�. size_visit�� 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit�� �ִ� �湮���� �ٽ� �ʱ�ȭ
					info_visit.pop_back();
				}
			}
		}
		else if (type_cctv[pos].type == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i�� 90�� ȸ������ ���ܳ��� ��� ����
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
				for (int i = 0; i<cnt; i++)
				{
					//���� visit�Ȱ��� ��ŭ pop���ش�. size_visit�� 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit�� �ִ� �湮���� �ٽ� �ʱ�ȭ
					info_visit.pop_back();
				}
			}
		}
		else if (type_cctv[pos].type == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i�� 90�� ȸ������ ���ܳ��� ��� ����
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
				for (int i = 0; i<cnt; i++)
				{
					//size ��ŭ pop���ش�. size_visit�� 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit�� �ִ� �湮���� �ٽ� �ʱ�ȭ
					info_visit.pop_back();
				}
			}
		}
		else if (type_cctv[pos].type == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i�� 90�� ȸ������ ���ܳ��� ��� ����
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
				for (int i = 0; i<cnt; i++)
				{
					//size ��ŭ pop���ش�. size_visit�� 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit�� �ִ� �湮���� �ٽ� �ʱ�ȭ
					info_visit.pop_back();
				}
			}
		}
		else
		{
			//5
			for (int i = 0; i < 5; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i�� 90�� ȸ������ ���ܳ��� ��� ����
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
				for (int i = 0; i<cnt; i++)
				{
					//size ��ŭ pop���ش�. size_visit�� 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit�� �ִ� �湮���� �ٽ� �ʱ�ȭ
					info_visit.pop_back();
				}
			}
		}
	}
	
}
int main()
{
	int cnt_zero = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			if (0 < map[i][j] && map[i][j] < 6)
			{
				cnt_cctv++; // cctv �� ���� ���ϱ�
				type_cctv.push_back({ i,j, map[i][j] }); // ��ǥ�� cctv���� �ֱ�
			}
			if (map[i][j] == 0)
			{
				cnt_zero++;
			}
		}
	}
	size_cctv = type_cctv.size();
	solve(0, 0, 0);

	printf("%d\n", cnt_zero-cnt_max);
	
}