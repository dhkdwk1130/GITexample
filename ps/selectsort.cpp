#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int arr[] = { 1,10, 5,6,7,8,9,2,4,3 ,92, 45 , 333, 100, 44};
	int min; // ���� ���� ���� �ε���
	int tmp; // ��ȯ�� �ʿ��� ����
	int size;
	int index;
	size = sizeof(arr) / sizeof(int);
	
	for (int i = 0; i < size - 1; i++) // ���� �ε���
	{
		min = 0;
		for (int j = i; j < size; j++)
		{
			if (min < arr[j])
			{
				min = arr[j];
				index = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
	for(int var : arr)
	{
		printf("%d ", var);
	}
}
/* �� ��(����)� �� ���� ����� ���� ����� ����.*/

