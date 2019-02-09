all:
	gcc -m32 -g -fpic -shared mlpic_dataonly.c -o libmlpic_dataonly.so
	# gcc -m32 -g driver.c -o driver -L. -lmlpic_dataonly
	gcc -m32 -g driver.c -o driver -L. -lmlpic_dataonly
clean:
	rm *.o libmlpic_dataonly.so
