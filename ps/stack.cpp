#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> v; //입력 데이터 동적으로 저장받는 배열
stack<int> s;
int k;
void solve() // 0이 등장하면 스택 자료 꺼내고 아니면 push하는 함수
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
	while (!s.empty()) // s[0]....s[size-1] for문으로 접근하려했으나 stack 스펙문서보고 안되는걸 알게됨..
	{
		ret += s.top();
		s.pop();
	}
	printf("%d", ret);
}