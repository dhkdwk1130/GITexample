#include<iostream>
//더하기 사이클
using namespace std;
int main()
{
	int N;
	int ten;
	int before;
	int after;
	int cnt = 1;
	bool isSame = true;
	int newnum = 0;
	scanf("%d", &N);
	newnum = N;
	while (isSame)
	{
		ten = newnum / 10;
		before = newnum % 10;
		after = ten + before;
		after = after % 10;
		newnum = (before * 10) + after;
		if (newnum == N)
			isSame = false;
		else
			cnt++;
	}
	printf("%d", cnt);
}