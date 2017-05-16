# Ahnaf Raihan
# Sorting Algorithms

all:	SortingAlgorithms

SortingAlgorithms:	main.o
	g++ main.o -o SortingAlgorithms.exe

main.o:	main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o SortingAlgorithms.exe

