#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

string map[10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void solve(int x, int y)
{
	//x,y�������� �󿵿� ��ĥ�ϴ� �Լ�
	int tx, ty;
	map[x][y] = '*';
	for (int i = 0; i<4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx<0 || tx >9 || ty<0 || ty>9) continue;
		if (map[tx][ty] == '_')
		{
			solve(tx, ty);
		}
	}
}
int main()
{
	int x, y;
	
	for (int i = 0; i< 10; i++)
	{
		cin >> map[i];
	}
	scanf("%d %d", &x, &y);
	if(map[y][x] != '*')
		solve(y, x); //x,y���� ��ä��� Ž�� 
	for (int i = 0; i< 10; i++)
	{
		for (int j = 0; j< 10; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
