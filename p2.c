/*Reads in 2 matrices from a text file, multiplies them together, and outputs the product.
10/02/19
p2
CS320
Brian Duong */
#include "p2.h"

void read_matrices(int **A, int **B, int **C,  int *m, int *n, int *p, char *data){
	FILE * fp;
	int i,j;
	int *tempptr;
	
	if ((fp = fopen(data, "r")) == NULL) {			/* checks to see if input file actually opens */
	    printf("Unable to open %s.\n", data);
	    return;
	}

	fscanf(fp, "%d", m);		/* scans in rows and cols of matrices A and B */
	fscanf(fp, "%d", n);
	fscanf(fp, "%d", p);

	*A = (int *) malloc(*(m) * *(n) * sizeof(int));			/* allocates memory for all three matrices */
	*B = (int *) malloc(*(n) * *(p) * sizeof(int));
	*C = (int *) malloc(*(m) * *(p) * sizeof(int));

	if(*A == NULL){			/* checks to see if malloc works */
		return;
	}

	if(*B == NULL){
		return;
	}

	if(*C == NULL){
		return;
	}

	for(i = 0; i < *m; i++){			/* fills matrix A with data from text file */
		for(j = 0; j < *n; j++){
			tempptr = (*A + (i * *(n)) + j);
			fscanf(fp, "%d", tempptr);
		}
	}

	for(i = 0; i < *n; i++){
		for(j = 0; j < *p; j++){
			tempptr = (*B + (i * *(p)) + j);
			fscanf(fp, "%d", tempptr);
		}
	}
}



void print_matrix(int *matrix, int rows, int cols){
    int i, j;

    for(i=0; i < rows; i++)
	{
        for(j=0; j < cols; j++)
		{
            printf("%3d", *(matrix + i * cols + j));	/* prints each number with 3 spaces available */
        }
        printf("\n");
    }
}



void mult_matrices(int *A, int *B, int *C, int m, int n, int p){
	int i, j, k;
	for(i = 0; i < m; i++){			
		for(j = 0; j < p; j++){
			*(C + i * p + j) = 0;
			for(k = 0; k < n; k++){
				*(C + i * p + j) += *(A + i * n + k) * *(B + k * p + j); 
			}
		}
	}
}


int main(int argc, char **argv){

	char *fname = *(argv + 1);
	int *A, *B, *C;
	int m, n, p;

	read_matrices(&A, &B, &C, &m, &n, &p, fname);

	mult_matrices(A, B, C, m, n, p);


	printf("Program #2, cssc0474, Brian Duong\n");

	printf("Matrix A contents:\n");
	print_matrix(A, m, n);
	printf("\n");
	printf("Matrix B contents:\n");
	print_matrix(B,n,p);
	printf("\n");
	printf("Matrix A * B is:\n");
	print_matrix(C,m,p);
	printf("\n");
	printf("The datafile read for this example is: %s\n", fname);

	return 0;
}





