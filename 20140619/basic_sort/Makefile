main.exe: ./main.o ./sort.o
	gcc -o ./bin/main.exe ./main.o ./sort.o
main.o: ./src/main.c
	gcc -c ./src/main.c -I ./include
sort.o: ./src/sort.c
	gcc -c ./src/sort.c -I ./include

