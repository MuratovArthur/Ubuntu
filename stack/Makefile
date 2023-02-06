Flags = -Wall -Wextra -pedantic-errors -std=c++20

app: Makefile app.o stack.o
	g++ $(Flags) -o app app.o stack.o

app.o : Makefile app.cpp stack.h
	g++ -c $(Flags) app.cpp -o app.o

stack.o : Makefile stack.cpp stack.h
	g++ -c $(Flags) stack.cpp -o stack.o
