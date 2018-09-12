#include<iostream>
#include<cstring>
using namespace std;
int base_size = 1000; // 1000��
int cnt_score[101]; // 0~100���� �ִ� �������� 
int solve()
{
	int num;
	int max_score = -1; // �Ȱ��� �������� �ִ�����
	int max_count = -1; // �ֺ󰳼�
	for (int i = 0; i < base_size; i++)
	{
		cin >> num;
		cnt_score[num]++; // �ش������� ������ �ϳ��� ���� ����
	}
	for (int i = 0; i <= 100; i++)
	{
		if (cnt_score[i] >= max_count) // �ִ� ���� ã�� 
		{
			max_count = cnt_score[i];  // �ִ� ���� ���� 
			if(max_count < i) // �������� ������ ũ�ٸ�
				max_score = i; // �ִ� ���� ���� 
		}
	}
	return max_score; // Ž������ �ִ� ���� ��ȯ
}
int main()
{
	int T; //test case
	int t; // case �ѹ� �Է¿� 
	int ret; // ���
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> t;
		ret = solve(); // �ֺ�� ���ϴ� �Լ� ȣ�� 
		cout << "#" << i << ' ' << ret << endl;
		memset(cnt_score, 0, sizeof(cnt_score)); // cnt_score �ʱ�ȭ
	}
}