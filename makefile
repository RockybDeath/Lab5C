main: main.c bmp_struct.c
	gcc -lm  bmp_struct.c main.c -o main
remove:
	rm -f main
