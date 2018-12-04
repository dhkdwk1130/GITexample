#include<iostream>
#include<vector>
#define left 2
#define right 0
#define up 1
#define down 3

using namespace std;
vector<int> v;// 이동지시사항들
int visit[101][101];
int dx[] = { 0, -1,0,1 }; // 0 right 1 up 2 left 3 down 
int dy[] = { 1, 0,-1,0 };
int main()
{
	int count = 0;
	int N;
	int x, y, d, g;//x는 맵에서 열요소, y는 맵에서 행요소
	scanf("%d", &N);
	while (N--)
	{
		int endx, endy; //끝좌표
		scanf("%d %d %d %d", &y, &x, &d, &g); // x, y좌표를 맵에 맞게 사용할수 있음
											  //0세대 그리기
		endx = x;
		endy = y;
		visit[x][y] = 1;
		endx += dx[d];
		endy += dy[d];
		visit[endx][endy] = 1;
		v.push_back(d); // vector에 다음 세대 그리기 위한 방향 넣음
		while (g--)
		{
			int vsize = v.size();
			for (int i = vsize - 1; i >= 0; i--) // v요소의 끝에서부터 처음까지 조사
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