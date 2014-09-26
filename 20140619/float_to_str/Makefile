main.exe: ./main.o ./float_to_str.o
	gcc -o ./bin/main.exe ./main.o ./float_to_str.o
main.o: ./src/main.c
	gcc -c ./src/main.c -I ./include
float_to_str.o: ./src/float_to_str.c
	gcc -c ./src/float_to_str.c -I ./include

