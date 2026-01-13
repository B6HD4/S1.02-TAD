exe : main.o grille.o
	g++ -Wall -Wextra -Wpedantic -Wconversion -g grille.o main.o -o exe
main.o :
	g++ -c -Wall -Wextra -Wpedantic -Wconversion -g main.cpp -o main.o
grille.o :
	g++ -c -Wall -Wextra -Wpedantic -Wconversion -g grille.cpp -o grille.o
clean :
	rm -f *.o
	rm -f exe
	clear
