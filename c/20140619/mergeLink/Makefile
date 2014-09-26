main.exe: ./main.o ./Linklist.o
	gcc -o ./bin/main.exe ./main.o ./Linklist.o
main.o: ./src/main.c
	gcc -c ./src/main.c -I ./include
Linklist.o: ./src/Linklist.c
	gcc -c ./src/Linklist.c -I ./include

