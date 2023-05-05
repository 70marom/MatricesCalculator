#include "mymat.h"

void reset_mat(mat matrix)
{
	int i, j;
	for(i = 0; i < MAT_SIZE; i++) {
		for(j = 0; j < MAT_SIZE; j++)
			matrix[i][j] = 0;
	}
}

void read_mat(mat matrix, double array[])
{
	int i, j, k = 0;
	for(i = 0; i < MAT_SIZE; i++) {
		for(j = 0; j < MAT_SIZE; j++){
			matrix[i][j] = array[k]; /* store the number from the array */
			k++;
		}
	}
	print_mat(matrix);
}

void print_mat(mat matrix)
{
	int i, j;
	for(i = 0; i < MAT_SIZE; i++) {
		for(j = 0; j < MAT_SIZE; j++)
			printf("%7.2f\t\t", matrix[i][j]); /* print with a precision of 7.2 */
		printf("\n");
	}
	printf("\n");
}

void add_mat(mat mat1, mat mat2, mat result)
{
	int i, j;
	for(i = 0; i < MAT_SIZE; i++) { /* going through all the cells in the matrices */
		for(j = 0; j < MAT_SIZE; j++)
			result[i][j] = mat1[i][j] + mat2[i][j];
	}
	print_mat(result);
}

void sub_mat(mat mat1, mat mat2, mat result)
{
	int i, j;
	for(i = 0; i < MAT_SIZE; i++) { /* going through all the cells in the matrices */
		for(j = 0; j < MAT_SIZE; j++)
			result[i][j] = mat1[i][j] - mat2[i][j];
	}
	print_mat(result);
}

void mul_mat(mat mat1, mat mat2, mat result)
{
	int i, j, k, mulSum = 0;
	for(i = 0; i < MAT_SIZE; i++) {
		for(j = 0; j < MAT_SIZE; j++) {
			mulSum = 0;
			for(k = 0; k < MAT_SIZE; k++) /* from the definition of matrices mult */
				mulSum+= mat1[i][k] * mat2[k][j];
			result[i][j] = mulSum;
		}
	}
	print_mat(result);
}

void mul_scalar(mat mat1, double value, mat result)
{
	int i, j;
	for(i = 0; i < MAT_SIZE; i++) { /* going through all the cells in the matrices */
		for(j = 0; j < MAT_SIZE; j++)
			result[i][j] = mat1[i][j] * value; /* mult by the given scalar */
	}
	print_mat(result);
}

void trans_mat(mat mat1, mat result)
{
	int i, j;
	mat tmpMat;
	reset_mat(tmpMat);
	for(i = 0; i < MAT_SIZE; i++) { /* copying the matrix to a temp one, but changing the indexes (i,j to j,i) */
		for(j = 0; j < MAT_SIZE; j++)
			tmpMat[i][j] = mat1[j][i];
	}
	for(i = 0; i < MAT_SIZE; i++) {
		for(j = 0; j < MAT_SIZE; j++)
			result[i][j] = tmpMat[i][j]; /* storing the result in the result matrix */
	}
	print_mat(result);
}







