#include "mymat.h"
#include "errors.h"
#include "mainmat.h"

int main()
{
	mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;
	mat *MATS[6];
	int i, j, matrixNum;
	double scalar;
	double numbers[16];
	char input[MAX_LINE_INPUT];
	char *commands[] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat", "mul_scalar", "trans_mat", "stop"};
	char *inputPtr;
	char *afterScal;
	MATS[0] = &MAT_A, MATS[1] = &MAT_B, MATS[2] = &MAT_C, MATS[3] = &MAT_D, MATS[4] = &MAT_E, MATS[5] = &MAT_F;
	for(i = 0; i < 6; i++) { /* reset all the matrices */
		reset_mat(*MATS[i]);
	}
	while(1){
		start:;
		printf("\nPlease enter the command and the required arguments, press ENTER after that\n>:");
		if(fgets(input, MAX_LINE_INPUT, stdin) == NULL) { /* if it's an EOF, assuming the input won't be more than 200 chars (much more than enough) */
			printf("\nUnexpected end of file, closing program\n");
			return 0;
		}
		printf("%s\n", input); /* print the input */
		inputPtr = input;
		inputPtr = getFstWord(inputPtr);

		i = whatComm(inputPtr); /* store what is the requested command */

		if(i == UNDEFINED) {
			printf("Undefined command name\n");
			continue;
		}

		inputPtr = inputPtr + strlen(commands[i]); /* jump to parameters */
		spacesRemoval(inputPtr); /* remove all the spaces from the input */
		if(inputPtr[0] == ',') {
			printf("Illegal comma\n");
			continue;
		}

		if(i == STOP) {
			EXTRA_TEXT(inputPtr[1])
			printf("You chose to close the program, goodbye!\n");
			return 0;
		}
	
		MISSING_PARAM(inputPtr[0]) /* check for a parameter */

		if(!isMat(&inputPtr[0])) {
			printf("Undefined matrix name\n");
			continue;
		}

		if(i == PRINT_MAT) {
			EXTRA_TEXT(inputPtr[PAST_ARG]) /* check for extra text in the end of the command */
			print_mat(*MATS[whichMat(inputPtr[PAST_ARG-1])]); /* if the input is fine - print the matrix */
			continue;
		}
	
		if(i == READ_MAT) {
			memset(numbers, 0, sizeof(numbers));
			matrixNum = whichMat(inputPtr[PAST_ARG-1]);
			inputPtr = inputPtr + PAST_ARG; /* get to the numbers */
			if(inputPtr[0] != ',') {
				NO_NUMBERS(inputPtr[0]) /* check if there're numbers */
				MISSING_COMMA(inputPtr[0]) /* check for a comma */
			}
			NO_NUMBERS(inputPtr[1])
			if((!isdigit(inputPtr[1])) && (inputPtr[1] != '-' && !isdigit(inputPtr[2]))) /* if it's not a legal number */
			{
				CONSECUTIVE_COMMA(inputPtr[1])
				printf("Argument is not a real number\n");
				continue;
			}
			numbers[0] = strtod(inputPtr + 1, &inputPtr); /* covert from string to double */
			for(j = 1; inputPtr[0] && j < 16; j++)
			{
				MISSING_COMMA(inputPtr[0])
				if((!isdigit(inputPtr[1])) && (inputPtr[1] != '-' && !isdigit(inputPtr[2])))
				{
					printf("Extraneous text after end of command\n");
					goto start;
				}
				numbers[j] = strtod(inputPtr + 1, &inputPtr);
				if(inputPtr[1] == ',')
				{
					printf("Multiple consecutive commas\n");
					goto start;
				}
			}
			read_mat(*MATS[matrixNum], numbers); /* after all the numbers are stored in the array */
	
			continue;
		}
	
		/* two arguments section*/

		MISSING_COMMA(inputPtr[PAST_ARG])

		if(i == MUL_SCALAR) {
			if(!isdigit(inputPtr[PAST_ARG + 1]))
			{
				MISSING_PARAM(inputPtr[PAST_ARG + 1])
				CONSECUTIVE_COMMA(inputPtr[PAST_ARG + 1])
				printf("Argument is not a scalar\n");
				continue;		
			}

			scalar = strtod(inputPtr+ (PAST_ARG + 1), &afterScal); /* covert the scalar to double */
			MISSING_COMMA(afterScal[0])

			if(!isMat(afterScal+1)) { /* plus 1 for the comma */
				MISSING_PARAM(afterScal[1])
				CONSECUTIVE_COMMA(afterScal[1])
				printf("Undefined matrix name\n");
				continue;
			}
			EXTRA_TEXT(afterScal[PAST_ARG + 1])
			mul_scalar(*MATS[whichMat(inputPtr[PAST_ARG-1])], scalar, *MATS[whichMat(afterScal[PAST_ARG])]); /* after all the tests perform the operation */
			continue;
		}
	
		if(i == TRANS_MAT) {
			if(!isMat(&inputPtr[PAST_ARG + 1])) { /* plus 1 for the comma */
				MISSING_PARAM(inputPtr[PAST_ARG + 1])
				CONSECUTIVE_COMMA(inputPtr[PAST_ARG + 1])
				printf("Undefined matrix name\n");
				continue;
			}
			EXTRA_TEXT(inputPtr[PAST_ARG + PAST_ARG + 1]) /* plus 1 for the comma */
		
			trans_mat(*MATS[whichMat(inputPtr[PAST_ARG-1])], *MATS[whichMat(inputPtr[PAST_ARG*2])]); /* after all the tests perform the operation */
			continue;
		}

		if(i == ADD_MAT || i == SUB_MAT || i == MUL_MAT) {
			if(!isMat(&inputPtr[PAST_ARG + 1])) { /* plus 1 for the comma */
				MISSING_PARAM(inputPtr[PAST_ARG + 1])
				CONSECUTIVE_COMMA(inputPtr[PAST_ARG + 1])
				printf("Undefined matrix name\n");
				continue;
			}

			MISSING_COMMA(inputPtr[PAST_ARG + PAST_ARG + 1]) /* plus 1 for comma*/

			if(!isMat(&inputPtr[PAST_ARG + PAST_ARG + 2])) { /* plus 2 for 2 commas */
				MISSING_PARAM(inputPtr[PAST_ARG + PAST_ARG + 2]);
				CONSECUTIVE_COMMA(inputPtr[PAST_ARG + PAST_ARG + 2]);
				printf("Undefined matrix name\n");
				continue;
			}
			/* if the last two parameters are matrices then the input is fine */
			EXTRA_TEXT(inputPtr[3 * PAST_ARG + 2]);
		
			/* because the input is fine we can do the requested command */
			if(i == ADD_MAT)
				add_mat(*MATS[whichMat(inputPtr[PAST_ARG-1])], *MATS[whichMat(inputPtr[PAST_ARG*2])], *MATS[whichMat(inputPtr[PAST_ARG*3+1])]);
			if(i == SUB_MAT)
				sub_mat(*MATS[whichMat(inputPtr[PAST_ARG-1])], *MATS[whichMat(inputPtr[PAST_ARG*2])], *MATS[whichMat(inputPtr[PAST_ARG*3+1])]);
			if(i == MUL_MAT)
				mul_mat(*MATS[whichMat(inputPtr[PAST_ARG-1])], *MATS[whichMat(inputPtr[PAST_ARG*2])], *MATS[whichMat(inputPtr[PAST_ARG*3+1])]);
			continue;
		}

	}
	return 0;
}
