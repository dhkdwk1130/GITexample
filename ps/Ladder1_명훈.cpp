#include<iostream>
using namespace std;
int map[101][101];

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int tr, tl;
		int ret = 0;
		int t;
		cin >> t;
		for (int i = 1; i <= 100; i++)
		{
			for (int j = 1; j <= 100; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for (int s = 1; s <= 100; s++)
		{
			//s는 선택된 열번호
			tr = 1;
			tl = s;
			if (map[tr][tl] == 0)
				continue;
			while (tr != 100) // 바닥까지 내려갔다면 끝
			{
				if (map[tr][tl + 1] == 1)
				{
					// 오른쪽에 1이있는경우
					tl++;
					while (map[tr + 1][tl] != 1) // 아래쪽이 1이 아닐떄동안 
					{
						tl = tl + 1;
					}

				}
				else if (map[tr][tl - 1] == 1)
				{
					// 왼쪽에 1이있는경우 
					tl--;
					while (map[tr + 1][tl] != 1) // 아래쪽이 1이 아닐떄동안 
					{
						tl = tl - 1;
					}
				}
				//좌우 아무것도 없다면 
				tr++;

			}
			if (map[tr][tl] == 2)
			{
				ret = s - 1;
				break;
			}
		}
		cout << "#" << t << ' ' << ret << '\n';
	}
}