#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int vector_add(int *A, int *B, int *C, int dimension);

int main(int argc, char **argv)
{
	int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int B[] = { 0, 1, 2, 0, 1, 2, 0, 1, 2, 0 };
	int C[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int dimension = sizeof(A)/sizeof(int);
	int i = 0;

	vector_add(A, B, C, dimension);

	printf("wrapper start printing vector C\n");
	for (i=0;i<dimension;i++)
		printf("%d ", C[i]);
	printf("\n");

	return 0;
}


