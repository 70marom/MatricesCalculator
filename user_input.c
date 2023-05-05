#include "mymat.h"

char *getFstWord(char *str)
{
	int i;
	for(i = 0; str[i] && (str[i] == ' ' || str[i] == '\t'); i++); /* jumpin to the word, ignoring tabs and spaces */
	return str + i;
}

int whatComm(char *str)
{
	char *commands[] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat", "mul_scalar", "trans_mat", "stop"};
	int i, count = 0;
	for(i = 0; str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != ','); i++, count++);
	for(i = 0; i < 8; i++) { /* 8 = num of funcs*/
		if(!strncmp(commands[i], str, count) && strlen(commands[i]) == count) /* comparing with all the commands */
			return i; /* if it's a command, return it's index */
	}
	return -1;
}

void spacesRemoval(char *str){
	int i;
    int count = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') /* removing from the string all the spaces, tabs and newlines */
            str[count++] = str[i];
    }
    str[count] = '\0';
    str[count+1] = '\0';
}

int whichMat(char matSign)
{
	if(matSign == 'A')
		return 0;
	if(matSign == 'B')
		return 1;
	if(matSign == 'C')
		return 2;
	if(matSign == 'D')
		return 3;
	if(matSign == 'E')
		return 4;
	return 5; /* it's F for sure so return 5 */
}

int isMat(char *str)
{
	if(strncmp("MAT_", str, 4) || str[4] < 'A' || str[4] > 'F') /* there are only matrices from A to F */
		return 0;
	return 1;
}
