#include<iostream>
#include<cstring>
#define LEFT 6
#define RIGHT 2
using namespace std;
int cnt_cmd;
int wheel[4][8]; // 바퀴 0, 1, 2, 3
// 0 1 2 3 4 로 0은 12시방향 
int flag[4]; // 4바퀴의 회전여부 
void Check(int wheel[][8])
{
	if (wheel[0][RIGHT] == wheel[1][LEFT])
	{
		flag[0] = -1;
	}
	else
	{
		flag[0] = 1;
	}
	if (wheel[1][RIGHT] == wheel[2][LEFT])
	{
		flag[1] = -1;
	}
	else
	{
		flag[1] = 1;
	}
	if (wheel[2][RIGHT] == wheel[3][LEFT])
	{
		flag[2] = -1;
	}
	else
		flag[2] = 1;

}
void moveLeft(int wheel[][8] , int wheelnum)
{
	int tmp = wheel[wheelnum][RIGHT];
	for (int i = 3; i <= 7; i++)
	{
		wheel[wheelnum][i - 1] = wheel[wheelnum][i];
	}
	wheel[wheelnum][7] = wheel[wheelnum][0];
	wheel[wheelnum][0] = wheel[wheelnum][1];
	wheel[wheelnum][1] = tmp;
}
void moveRight(int wheel[][8] , int wheelnum)
{
	int tmp = wheel[wheelnum][LEFT];
	for (int i = 5; i >= 0; i--)
	{
		wheel[wheelnum][i + 1] = wheel[wheelnum][i];
	}
	wheel[wheelnum][0] = wheel[wheelnum][7];
	wheel[wheelnum][7] = tmp;
}
int main()
{
	for (int j = 0; j < 8; j++)
	{
		scanf("%1d", &wheel[0][j]);
	}
	for (int j = 0; j < 8; j++)
	{
		scanf("%1d", &wheel[1][j]);
	}
	for (int j = 0; j < 8; j++)
	{
		scanf("%1d", &wheel[2][j]);
	}
	for (int j = 0; j < 8; j++)
	{
		scanf("%1d", &wheel[3][j]);
	}
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d ", wheel[i][j]);
		}
		puts("");
	}*/
	cin >> cnt_cmd;
	int select, dir;
	int ret = 0;
	int tmp;
	for (int i = 0; i < cnt_cmd; i++)
	{
		scanf("%d %d", &select, &dir);
		memset(flag, 0, sizeof(flag));
		// 한번의 명령 마다 12시 방향값들을 더해나간다.

		Check(wheel);
		if (select == 1)
		{
			// 1번 바퀴일때 
			if (dir == -1)
			{
				moveLeft(wheel, 0);
				if (flag[0] == 1) // 다르다면 회전한다.
				{
					//반시계일때
					moveRight(wheel, 1);
					if (flag[1] == 1)
					{
						moveLeft(wheel, 2);
						if (flag[2] == 1)
						{
							moveRight(wheel, 3);
						}
					}
				}
			}
			else if (dir == 1)
			{
				//시계일때
				moveRight(wheel, 0);
				if (flag[0] == 1) // 다르다면 회전한다.
				{
					moveLeft(wheel, 1);
					if (flag[1] == 1)
					{
						moveRight(wheel, 2);
						if (flag[2] == 1)
						{
							moveLeft(wheel, 3);
						}
					}
				}
			}
		}
		else if (select == 2)
		{
			if (dir == -1)
			{
				moveLeft(wheel, 1); // 두번째바퀴 시계반대돌리고
				if (flag[0] == 1)
				{
					moveRight(wheel, 0); // 첫번째바퀴 시계방향돌린다.
				}
				if (flag[1] == 1)
				{
					moveRight(wheel, 2);
					if (flag[2] == 1)
					{
						moveLeft(wheel, 3);
					}
				}
			}
			else if (dir == 1)
			{
				moveRight(wheel, 1);
				if (flag[0] == 1)
				{
					moveLeft(wheel, 0);
				}
				if (flag[1] == 1)
				{
					moveLeft(wheel, 2);
					if (flag[2] == 1)
					{
						moveRight(wheel, 3);
					}
				}
			}
		}


		else if (select == 3)
		{
			if (dir == -1)
			{
				moveLeft(wheel, 2);
				if (flag[1] == 1)
				{
					//왼쪽이 달라서 돌릴수잇다면 
					moveRight(wheel, 1);
					if (flag[0] == 1)
					{
						moveLeft(wheel, 0);
					}
				}
				if (flag[2] == 1)
				{
					moveRight(wheel, 3);
				}
			}
			else if (dir == 1)
			{
				moveRight(wheel, 2);
				if (flag[1] == 1)
				{
					moveLeft(wheel, 1);
					if (flag[0] == 1)
					{
						moveRight(wheel, 0);
					}
				}
				if (flag[2] == 1)
				{
					moveLeft(wheel, 3);
				}
			}
		}
		else if (select == 4)
		{
			if (dir == -1)
			{
				moveLeft(wheel, 3);
				if (flag[2] == 1)
				{
					moveRight(wheel, 2);
					if (flag[1] == 1)
					{
						moveLeft(wheel, 1);
						if (flag[0] == 1)
						{
							moveRight(wheel, 0);
						}
					}
				}
			}
			else if (dir == 1)
			{
				moveRight(wheel, 3);
				if (flag[2] == 1)
				{
					moveLeft(wheel, 2);
					if (flag[1] == 1)
					{
						moveRight(wheel, 1);
						if (flag[0] == 1)
						{
							moveLeft(wheel, 0);
						}
					}
				}
			}
		}

	}
	ret = 0;
	if (wheel[0][0] == 1)ret += 1;
	if (wheel[1][0] == 1)ret += 2;
	if (wheel[2][0] == 1)ret += 4;
	if (wheel[3][0] == 1)ret += 8;

	cout << ret;
}