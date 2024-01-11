all: 
	gcc -Wall --pedantic src/*c -o bin/mrowka
	@rm -r wyniki/*
