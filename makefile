compile-run: build run
	build
	

build:
	gcc main.c operations.c -o main

run:
	.\main

clean:
	rm -f main