#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
stack<int> v1, v2;
vector<int> ret;
int main()
{
	char num;
	int number;
	int add = 0;
	int flag = 1;
	int tmp;
	int cnt1 = 0;
	int cnt2 = 0;
	int retsize = 0;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int s1_Size;
	int s2_Size;
	s1_Size = s1.size();
	s2_Size = s2.size();
	for (int i = 0; i<s1_Size; i++)
	{
		v1.push(s1[i]-'0');
	}
	for (int i =0; i<s2_Size; i++)
	{
		v2.push(s2[i] - '0');
	}
	if (s1_Size > s2_Size)
	{
		while (!v2.empty())
		{
			int tmp1, tmp2, tmp3;
			tmp1 = v1.top();
			tmp2 = v2.top();
			v2.pop();
			v1.pop();
			tmp3 = tmp1 + tmp2 + add;
			if (tmp3 >= 10) add = 1;
			else add = 0;
			tmp3 = tmp3 % 10;
			ret.push_back(tmp3);
			retsize++;
		}
	}
	else
	{
		while (!v1.empty())
		{
			int tmp1, tmp2, tmp3;
			tmp1 = v1.top();
			tmp2 = v2.top();
			v2.pop();
			v1.pop();
			tmp3 = tmp1 + tmp2 + add;
			if (tmp3 >= 10) add = 1;
			else add = 0;
			tmp3 = tmp3 % 10;
			ret.push_back(tmp3);
			retsize++;
		}
	}
	while (!v1.empty())
	{
		tmp = v1.top() + add;
		v1.pop(); //나머지 다 빼준다.
		if (tmp >= 10) add = 1;
		else add = 0;
		ret.push_back(tmp % 10);
		retsize++;
	}
	while (!v2.empty())
	{
		tmp = v2.top() + add;
		v2.pop(); //나머지 다 빼준다.
		if (tmp >= 10) add = 1;
		else add = 0;
		ret.push_back(tmp % 10);
		retsize++;
	}
	if (add == 1)
		printf("1");
	for(int i =retsize-1; i>=0; i--)
		printf("%d", ret[i]);
	
}