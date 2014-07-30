main.exe: ./main.o ./unique.o
	gcc -o ./bin/main.exe ./main.o ./unique.o
main.o: ./src/main.c
	gcc -c ./src/main.c -I ./include
unique.o: ./src/unique.c
	gcc -c ./src/unique.c  -I ./include
