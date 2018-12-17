#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, double>> v; // (����,Ű)....
char hak[][3] = { "A+","A0","A-","B+" 
,"B0" ,"B-" ,"C+" ,"C0" ,"C-","D0"};
bool cmp(const pair<int,double>& a, const pair<int, double>& b)
{
	return a.second > b.second;
}
int main()
{
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int n, k, percent;
		double num;
		int mid, last, pjt;
		int p1;
		int tmp;
		int p = 0;
		int key = 1;
		scanf("%d %d", &n, &k);
		percent = n / 10;
		p1 = percent; // p1�� ����
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &mid, &last, &pjt);
			num = (mid*0.35) + (last*0.45) + (pjt * 0.2);
			v.push_back(make_pair(key, num));
			key++;
		}
		sort(v.begin(), v.end(), cmp);
		//0 a+, 1 a, 2 a- ...
		for (int i = 0; i < n; i++)
		{
			tmp = v[i].first;
			if (p1 == 0)
			{
				p++;
				p1 = percent; // ��Ʈ���̤�
			}
			if (tmp == k)
			{
				printf("#%d %s\n", t, hak[p]); // %s�� ����ϴµ� %d�ξ��̤�, \n �������� ��Ʋ���� ������ �� ���...
				break;
			}
			p1--;
		}
		v.clear();
	}
}