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
			//s�� ���õ� ����ȣ
			tr = 1;
			tl = s;
			if (map[tr][tl] == 0)
				continue;
			while (tr != 100) // �ٴڱ��� �������ٸ� ��
			{
				if (map[tr][tl + 1] == 1)
				{
					// �����ʿ� 1���ִ°��
					tl++;
					while (map[tr + 1][tl] != 1) // �Ʒ����� 1�� �ƴҋ����� 
					{
						tl = tl + 1;
					}

				}
				else if (map[tr][tl - 1] == 1)
				{
					// ���ʿ� 1���ִ°�� 
					tl--;
					while (map[tr + 1][tl] != 1) // �Ʒ����� 1�� �ƴҋ����� 
					{
						tl = tl - 1;
					}
				}
				//�¿� �ƹ��͵� ���ٸ� 
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