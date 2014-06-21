main.exe:./main.o ./func.o 
	gcc -o ./bin/main.exe ./main.o ./func.o -I ./include
main.o: ./src/main.c
	gcc -c ./src/main.c -I ./include
func.o: ./src/func.c
	gcc -c ./src/func.c -I ./include


