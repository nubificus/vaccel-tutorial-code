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

	int ret = vector_add(A, B, C, dimension);
	if (ret) {
		printf("Error running operation\n");
		goto out;
	}
				
	printf("Operation successful!\n");
	printf("A: "); 
	for (i=0;i<dimension;i++)
		printf("%2d ", A[i]);
	printf("\n+\n");
	printf("B: "); 
	for (i=0;i<dimension;i++)
		printf("%2d ", B[i]);
	printf("\n=\n");
	printf("C: "); 
	for (i=0;i<dimension;i++)
		printf("%2d ", C[i]);
	printf("\n");

out:
	return ret;
}


