CC=clang

transFile: main.c fileOperations.c transaction.c
	$(CC) main.c fileOperations.c transaction.c -o app 
