#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M;
queue<int> q;
vector<int> v[1001];
int visit[1001];
void dfs(int s)
{
	visit[s] = 1;
	int size = v[s].size();
	printf("%d ", s);
	for (int i = 0; i < size; i++)
	{
		int next = v[s][i];
		if (!visit[next])
		{
			dfs(next);
		}
	}
}
void bfs(int s)
{
	int size;
	int now;
	visit[s] = 1;
	q.push(s);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		printf("%d ", now);
		size = v[now].size();
		for (int i = 0; i < size; i++)
		{
			int next = v[now][i];
			if (!visit[next])
			{
				q.push(next);
				visit[next] = 1;
			}
		}
	}
}
int main()
{
	int k;
	int a, b;
	cin >> N >> M >> k;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	dfs(k);
	memset(visit, 0, sizeof(visit));
	printf("\n");
	bfs(k);
}
