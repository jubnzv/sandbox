all: lib driver

lib:
	gcc -shared -o libexit.so libexit.c -fPIC

driver:
	gcc -I. -o driver -L. -lexit driver.c

clean:
	rm -rf libexit.so driver
