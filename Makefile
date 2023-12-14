CC=g++
SOURCES=main.cpp

run: build
	@./main

build:
	@$(CC) $(SOURCES) -o main 

clean:
	@rm -rf *.o 
