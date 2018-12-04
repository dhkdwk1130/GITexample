#include<iostream>
#include<vector>
using namespace std;
struct CCTV
{
	int x;
	int y;
	int type;
};
int map[9][9]; // 최대 8*8
int n, m;
int cnt_cctv;
int visit[9][9]; // 방문 표시맵
int size_cctv;
int cnt_max = -1;
vector < CCTV > type_cctv; // cctv 종류 넣기
vector <pair<int, int> > info_visit; // 방문된 좌표값 저장
int visiting(CCTV cctv, int d) 
{
	// cctv종류의 90도 방향에 따라서 맵을 방문해주고 몇개를 방문했는지 개수리턴 함수
	// type= 현재 cctv종류, d= 90도 회전에따른 방향
	int type = cctv.type;
	int x = cctv.x;
	int y = cctv.y;
	int cnt = 0;
	if ( type == 1)
	{ 
		if(d == 0) 
		{ // 오른방향인경우
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
					info_visit.push_back(make_pair(x, i)); // 방문된 좌표 input
					cnt++;
				}
			}
		}
		else if(d == 1)
		{ // 아래방향인경우
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
		{ //왼쪽방향인 경우
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
		{ //위쪽방향인 경우
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
		{//가로줄 방문표시
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
			{ // 왼쪽가는경우
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
		{ // 세로줄 방문표시
			for(int i = x-1; i>=0; i--)
			{ // 위로 가는로직
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
			{ // 아래로 가는로직
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
		{// 오른쪽방향
			for (int i = x - 1; i >= 0; i--)
			{ // 위로 가는로직
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
			{// 오른쪽 가는경우
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
		{// 90도회전해서 아래방향 (오른+아래)
			for (int i = y + 1; i < m; i++)
			{// 오른쪽 가는경우
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
			{ // 아래로 가는로직
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
		{ // 왼쪽가는방향 (아래+왼)
			for (int i = x + 1; i < n; i++)
			{ // 아래로 가는로직
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
		{ // 화살표 왼+위
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
			{ // 위로 가는로직
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
		{//왼+위+오른
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
			{ // 위로 가는로직
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
			{// 오른쪽 가는경우
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
		{//위+오른+아래
			for (int i = x - 1; i >= 0; i--)
			{ // 위로 가는로직
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
			{// 오른쪽 가는경우
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
			{ // 아래로 가는로직
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
		{//왼+아래+오른
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
			{ // 아래로 가는로직
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
			{// 오른쪽 가는경우
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
		{//왼+위+아래
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
			{ // 아래로 가는로직
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
			{ // 위로 가는로직
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
		{ // 아래로 가는로직
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
		{ // 위로 가는로직
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
		{// 오른쪽 가는경우
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
	// pos위치에 있는 cctv 종류에 따라서 그 종류의 90도 방향모두의 경우를 맵에 방문표시해주는 함수
	// pos+1 위치로 넘겨줄떄는 cnt_check를 하나 더해준다(한개의cctv를 확인했음을 알리기위해)
	if (cnt_check == size_cctv)
	{
		// 현재 확인된개수가 총 cctv개수라면 끝
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
				cnt = visiting(type_cctv[pos], i); // i는 90도 회전마다 생겨나는 모든 방향
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
			    for(int i =0; i<cnt; i++)
				{
					//size 만큼 pop해준다. size_visit는 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit에 있는 방문정보 다시 초기화
					info_visit.pop_back();
				}
			}
		}
		else if (type_cctv[pos].type == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i는 90도 회전마다 생겨나는 모든 방향
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
				for (int i = 0; i<cnt; i++)
				{
					//현재 visit된개수 만큼 pop해준다. size_visit는 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit에 있는 방문정보 다시 초기화
					info_visit.pop_back();
				}
			}
		}
		else if (type_cctv[pos].type == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i는 90도 회전마다 생겨나는 모든 방향
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
				for (int i = 0; i<cnt; i++)
				{
					//size 만큼 pop해준다. size_visit는 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit에 있는 방문정보 다시 초기화
					info_visit.pop_back();
				}
			}
		}
		else if (type_cctv[pos].type == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i는 90도 회전마다 생겨나는 모든 방향
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
				for (int i = 0; i<cnt; i++)
				{
					//size 만큼 pop해준다. size_visit는 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit에 있는 방문정보 다시 초기화
					info_visit.pop_back();
				}
			}
		}
		else
		{
			//5
			for (int i = 0; i < 5; i++)
			{
				cnt = visiting(type_cctv[pos], i); // i는 90도 회전마다 생겨나는 모든 방향
				solve(cnt_check + 1, pos + 1, cnt_visit + cnt);
				for (int i = 0; i<cnt; i++)
				{
					//size 만큼 pop해준다. size_visit는 
					int x = info_visit.back().first;
					int y = info_visit.back().second;
					visit[x][y] = 0; // info_visit에 있는 방문정보 다시 초기화
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
				cnt_cctv++; // cctv 총 개수 구하기
				type_cctv.push_back({ i,j, map[i][j] }); // 좌표와 cctv종류 넣기
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