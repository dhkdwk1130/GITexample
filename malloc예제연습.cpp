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
	ptr = (int *)realloc(ptr, n2*sizeof(int));//ptr이 가리키고있는 배열 크기를 n2만큼 늘린다. 그리고 크기는 추가가 아닌 덮어쓰면서 커지는 방식임.
	printf("Addresses of newly allocated memory : ");
	for (i = 0; i < n2; i++)
		printf("%d ", ptr + i);
	free(ptr);
	return 0; //프로그램 종료
}