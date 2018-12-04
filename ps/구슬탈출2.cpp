#include<iostream>
#include<cstdio>
using namespace std;
char board[11][11];
//4방향 기울리는 함수작성
//입력받는 메인함수
int N, M;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &board[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c", board[i][j]);
		}
		puts("");
	}
}