#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> v; //�Է� ������ �������� ����޴� �迭
stack<int> s;
int k;
void solve() // 0�� �����ϸ� ���� �ڷ� ������ �ƴϸ� push�ϴ� �Լ�
{
	for (int i = 0; i<k; i++)
	{
		if (v[i] != 0)
		{
			s.push(v[i]);
		}
		else
		{
			if (!s.empty())
			{
				s.pop();
			}
		}
	}
}

int main()
{

	int num;
	int ret = 0;
	cin >> k;
	for (int i = 0; i<k; i++)
	{
		scanf("%d", &num);
		v.push_back(num);
	}
	solve();
	while (!s.empty()) // s[0]....s[size-1] for������ �����Ϸ������� stack ���幮������ �ȵǴ°� �˰Ե�..
	{
		ret += s.top();
		s.pop();
	}
	printf("%d", ret);
}