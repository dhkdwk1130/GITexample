#include<iostream>
#include<vector>
#include<string>
using namespace std;
char check[6] = "croak"; // �����Ҹ�����(���Ҵ��) 5�� �������̱⶧����
vector <char> v; // �����Ҹ� �ѹ��ھ� �����ϴ� �༮
int main()
{
	int test_case;
	cin >> test_case;
	for(int t= 1; t<=test_case; t++)
	{
		bool flag = false;
		bool visit = false;
		int cnt = 0;
		int vsize = 0;
		int k = 0;
		int pos = 0;
		string str;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			v.push_back(str[i]);
		}
		//�����Ҹ� ����Ϸ�
		while (!v.empty())
		{
			//�����Ҹ� ��ü ������ �������� �ݺ��Ѵ�.
			vsize = v.size();
			k = 0; // ���� check�� ���� ���ڰ� ������ k ������ ����� �ٿ��ֱ����ؼ� �ʿ���
			pos = 0;
			flag = false;
			visit = false;
			for (int i = 0; i < vsize - k; i++)
			{
				if (v[i] == check[pos])
				{
					v.erase(v.begin() + i);
					k++; //size �ϳ� ����
					i--; // i���ڸ� ��������� �ϳ� ����
					pos++; // pos�� ���� ������ �غ��ϱ����� ����ġ�� �̵�
					if (pos == 5)
					{
						pos = 0;// �ٻ����� 0���� ������ ���� �����Ҹ��� �������� ����!
					}
					visit = true; // �� ���ڴ� �ִ�.
				}
			}
			//�ѷ����� ������ pos ��ġ Ȯ��
			if (pos != 0 || visit == false)
			{
				flag = true; // ���� �Ҹ� ���� Ȥ�� �����Ҹ� �ٸ����� �Ϻ� ���Ҵ�.��� �ǹ�
				break;
			}
			cnt++; // �ѷ����� ������ ���� ���� ��ġ�� �ִٸ� ī��Ʈ �����Ѵ�. 
		}
		if (flag)
		{
			printf("#%d -1\n", t);
			v.clear();
		}
		else
			printf("#%d %d\n", t, cnt);
		}
	
}