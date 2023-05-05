#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAT_SIZE 4

/* the data structure for the matrices, a static matrix with the size of 4 * 4 of the type double */
typedef double mat[4][4];

/* reset the given mat (the mat parameter) */
void reset_mat(mat);
/* store all the number from the double array in the given matrix */
void read_mat(mat, double[]);
/* print to the screen the given matrix */
void print_mat(mat);
/* the add operation for matrices, the first two matrices are the operands and the result will be stored in the last matrix */
void add_mat(mat, mat, mat);
/* the subtraction operation for matrices, the first two matrices are the operands and the result will be stored in the last matrix */
void sub_mat(mat, mat, mat);
/* the multiplication operation for matrices, the first two matrices are the operands and the result will be stored in the last matrix */
void mul_mat(mat, mat, mat);
/* the scalar multiplication operation for matrices, the double number is the scalar and the result will be stored in the last matrix */
void mul_scalar(mat, double, mat);
/* the transpose operation, the first matrix will be transposed and the result will be stored in the last matrix */
void trans_mat(mat, mat);

/* return a pointer to the first letter (skipping spaces and tabs) of the given string */
char *getFstWord(char *);
/* return the index of the given command from the array of commands, if the given string is not a command - return -1 */
int whatComm(char *);
/* removes all the spaces from the given string (including tabs) */
void spacesRemoval(char *);
/* return the number of the given matrix letter (A=0, B=1...) */
int whichMat(char);
/* return whether the given string is a defined matrix or not, if it is return 1, if not return 0 */
int isMat(char *);
