all:
	gcc -shared -fPIC -ldl -O2 -o lib.so lib.c
	gcc main.c -o main

clean:
	rm -rf *.o main lib.so
