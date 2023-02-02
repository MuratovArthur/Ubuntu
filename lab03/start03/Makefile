
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wall -pedantic-errors -std=c++20
CPP = g++


main : Makefile   main.o rational.o bigint.o 
	$(CPP) $(Flags) -o main   main.o rational.o bigint.o 

main.o : Makefile   main.cpp   rational.h bigint.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


rational.o : Makefile   rational.cpp   rational.h bigint.h 
	$(CPP) -c $(Flags) rational.cpp -o  rational.o


bigint.o : Makefile   bigint.cpp   bigint.h 
	$(CPP) -c $(Flags) bigint.cpp -o  bigint.o


