#include<iostream>
#include<cstring>
using namespace std;
int base_size = 1000; // 1000명
int cnt_score[101]; // 0~100점이 있는 개수정보 
int solve()
{
	int num;
	int max_score = -1; // 똑같은 개수에서 최대점수
	int max_count = -1; // 최빈개수
	for (int i = 0; i < base_size; i++)
	{
		cin >> num;
		cnt_score[num]++; // 해당점수가 있으면 하나씩 개수 증가
	}
	for (int i = 0; i <= 100; i++)
	{
		if (cnt_score[i] >= max_count) // 최대 개수 찾기 
		{
			max_count = cnt_score[i];  // 최대 개수 갱신 
			if(max_count < i) // 같은것중 점수가 크다면
				max_score = i; // 최대 점수 갱신 
		}
	}
	return max_score; // 탐색끝낸 최대 점수 반환
}
int main()
{
	int T; //test case
	int t; // case 넘버 입력용 
	int ret; // 결과
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> t;
		ret = solve(); // 최빈수 구하는 함수 호출 
		cout << "#" << i << ' ' << ret << endl;
		memset(cnt_score, 0, sizeof(cnt_score)); // cnt_score 초기화
	}
}