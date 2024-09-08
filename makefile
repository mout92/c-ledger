CC=clang
bin=./bin/

transFile: main.c fileOperations.c transaction.c
	$(CC) main.c fileOperations.c transaction.c -o $(bin)app
