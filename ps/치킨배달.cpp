#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int ans = 987654321; // 도시의 치킨거리
int M;
int visit[13];
vector<pair<int, int>> home; // 집좌표
vector<pair<int, int>> chicken; // 치킨 좌표
int csize;
int min(int a, int b) { return a < b ? a : b; }
void solve(int inow, int cnt_now)
{
	// m의 모든 경우를 고려해서 cnt_now가 M이 되는 순간 치킨 거리의 합들을 구해서
	// 최소값을 구하는 함수
	if (inow > csize) return; // 현재인덱스가 치킨 개수를 넘어가면 리턴
	if (cnt_now == M) // 최대 M개를 고를때
	{
		int d; // 두점사이의 거리
		int x1, x2;
		int y1, y2;
		int tmp = 0;
		int homesize = home.size();
		for (int i = 0; i < homesize; i++)
		{
			int minnum = 987654321;
			for (int j = 0; j < csize; j++)
			{
				if (visit[j]) // 선택된 치킨집만 거리를 계산하고 집과의 최소값을 찾는다.
				{
					d = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
					if (minnum > d)
						minnum = d;
				}
			}
			tmp += minnum;
			
		}
		ans = min(ans, tmp); //도시치킨거리 갱신
		return;
	}
	// 현재 치킨집을 선택하는 경우와 아닌경우 생성
	visit[inow] = 1;// 현재 치킨집 선택
	solve(inow + 1, cnt_now + 1); // 다음 치킨집 가고 선택했으므로 inow + 1한다.
	visit[inow] = 0; // 다른 경우를 해야하기에 선택된 치킨집 해제
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