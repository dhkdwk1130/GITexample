#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr, i, n1, n2;
	printf("Enter size of array : ");
	scanf("%d", &n1);
	ptr = (int*)malloc(n1 * sizeof(int));
	//ptr = (int*) calloc(n1, sizeof(int));
	for (i = 0; i < n1; i++)
	{
		printf("%d ", ptr + i);
	}
	printf("\nEnter new size of array: ");
	scanf("%d", &n2);
	ptr = (int *)realloc(ptr, n2*sizeof(int));//ptr�� ����Ű���ִ� �迭 ũ�⸦ n2��ŭ �ø���. �׸��� ũ��� �߰��� �ƴ� ����鼭 Ŀ���� �����.
	printf("Addresses of newly allocated memory : ");
	for (i = 0; i < n2; i++)
		printf("%d ", ptr + i);
	free(ptr);
	return 0; //���α׷� ����
}