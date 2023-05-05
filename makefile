mainmat: mainmat.o mymat.o user_input.o
	gcc -g -Wall -ansi -pedantic mainmat.o mymat.o user_input.o -o mainmat
mainmat.o: mainmat.c user_input.o mymat.h errors.h
	gcc -c -Wall -ansi -pedantic mainmat.c -o mainmat.o
mymat.o: mymat.c mymat.h
	gcc -c -Wall -ansi -pedantic mymat.c -o mymat.o
user_input.o: user_input.c mymat.h
	gcc -c -Wall -ansi -pedantic user_input.c -o user_input.o
