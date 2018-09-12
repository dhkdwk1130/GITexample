//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int month_day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//int base_year = 1;
//int base_month = 1;
//bool isYear(int year)
//{
//	if (year % 400 == 0)
//	{
//		return true;
//	}
//	if ((year % 100) != 0 && year % 4 == 0)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	ofstream fout("result.txt",ios::out | ios::trunc);
//	int year;
//	int month;
//	int index;
//	int total_day; //총일수
//	int tmp;
//	string s_month;
//	cout << "input year " << endl;
//	cin >> year;
//	cout << "input month " << endl;
//	cin >> month;
//	total_day = ((year - base_year) * 365);
//	tmp = year - base_year;
//	while(tmp>0)
//	{
//		if (isYear(tmp))
//		{
//			total_day += 1; // 윤년이있다면 하루씩 더 더함
//		}
//		tmp--;
//	} 
//
//	if (isYear(year))
//	{
//		month_day[1] = 29;
//	}
//	for (int i = 0; i < month - 1; i++)
//	{
//		total_day += month_day[i];
//	}
//	index = (total_day) % 7 + 1;
//	//index 0 : 일요일 1: 월요일 .... 6 토요일 시작
//	//2 화 3 수 4 목 5 금 6 토
//	char space = '\t';
//	if (month < 10)
//	{
//		s_month = to_string(month);
//	}
//	fout << "<" << year << "-" << s_month << ">" << '\n';
//	fout << "일" << '\t' << "월" << '\t' << "화" << '\t' << "수" << '\t' << "목" << '\t' << "금" << '\t' << "토" << '\n';
//	int cnt = index;
//	cout << index;
//	for (int i = 0; i < index; i++)
//		fout << '\t';
//	for (int i = 1; i <= month_day[month - 1]; i++)
//	{
//		fout <<i<<'\t';
//		if (cnt == 6)
//		{
//			fout << '\n';
//			cnt = 0;
//			continue;
//		}
//		cnt++;
//	}
//	fout.close();
//}
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char ch;
	fstream fs("test.txt", ios::out | ios::in |ios::trunc);
	char buf[] = "abcde";
	fs.write("abcde", 5);
	fs.seekg(0, ios::beg);
	fs.get(ch);
	fs.get(ch);
	fs.get(ch);
	cout << fs.tellg();
}