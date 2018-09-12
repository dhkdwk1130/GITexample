#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t_cnt; //시간 개수
int c_cnt; //치즈 개수
int r, l;
int map[101][101];
int visit[101][101];
int dx[] = { 1,-1,0,0 }; //0 상 1 하 2 좌 3 우
int dy[] = { 0,0,-1,1 };
// 한번의 탐색이 끝날때마다 맵체크
bool mapcheck(int x, int y) // 맵 범위 검사
{
	if (x < r && x >= 0 && y < l && y >= 0)
		return true;  // 범위내에 있으면 참
	else
		return false; // 범위내에 없으면 거짓
}
void dfs(int r, int l) // dfs 탐색  (0,0) 시작
{
	int tr, tl; // 이동할 좌표 dx,dy 더한값

	visit[r][l] = 1; // 현재 좌표 방문됨표시
	for (int i = 0; i < 4; i++)
	{
		tr = r + dx[i]; // 상, 하 ,좌 ,우로 각각 더해준다.
		tl = l + dy[i];
		if (!mapcheck(tr, tl)) // 각방향마다 맵검사
			continue;
		if (map[tr][tl] == 1) // 이동할 좌표가 1이라면 
		{
			map[tr][tl] = 0;    // 그 좌표를 0 으로 바꾼다. 
			visit[tr][tl] = 1; // 그 좌표를 방문했다로 표시
			c_cnt++; // 치즈 개수를 하나 증가한다.
		}
		if (map[tr][tl] == 0 && visit[tr][tl] != 1) // 이동할 좌표가 0이라면 그냥 이동한다. 단, 방문안되있어야함
		{
			dfs(tr, tl); // 이동가능한 좌표로 다시 탐색 시작 
		}
	}
}
bool isclean()  // 맵에 치즈가 전부 지워졌는지 확인 함수
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
		dfs(0, 0); //dfs 시작
		memset(visit, 0, sizeof(visit)); // 방문정보 초기화 
		t_cnt++; // dfs한번할때마다 한시간씩증가 
	}
	cout << t_cnt << '\n' << c_cnt;
}