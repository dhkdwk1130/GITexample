#include<iostream>
#include<vector>
#include<string>
using namespace std;
char check[6] = "croak"; // 울음소리문장(비교할대상) 5가 마지막이기때문에
vector <char> v; // 울음소리 한문자씩 저장하는 녀석
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
		//울음소리 저장완료
		while (!v.empty())
		{
			//울음소리 전체 문장이 빌때까지 반복한다.
			vsize = v.size();
			k = 0; // 만약 check와 같은 문자가 있으면 k 값으로 사이즈를 줄여주기위해서 필요함
			pos = 0;
			flag = false;
			visit = false;
			for (int i = 0; i < vsize - k; i++)
			{
				if (v[i] == check[pos])
				{
					v.erase(v.begin() + i);
					k++; //size 하나 줄임
					i--; // i제자리 만들기위해 하나 빼줌
					pos++; // pos는 다음 뺄것을 준비하기위해 그위치로 이동
					if (pos == 5)
					{
						pos = 0;// 다뺏으면 0으로 돌린후 다음 울음소리를 빼기위해 쎗팅!
					}
					visit = true; // 이 문자는 있다.
				}
			}
			//한루프가 끝나면 pos 위치 확인
			if (pos != 0 || visit == false)
			{
				flag = true; // 울음 소리 없다 혹은 울음소리 다못빼고 일부 남았다.라는 의미
				break;
			}
			cnt++; // 한루프가 끝나고 다음 빼줄 위치에 있다면 카운트 증가한다. 
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