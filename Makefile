#Rehan Javaid, rj3dxu, 10/12/2020, Makefile

wordPuzzle: wordPuzzle.o hashTable.o timer.o
	clang++ wordPuzzle.o hashTable.o timer.o

wordPuzzle.o: wordPuzzle.cpp
	clang++ -c wordPuzzle.cpp

hashTable.o: hashTable.cpp
	clang++ -c hashTable.cpp

timer.o: timer.cpp
	clang++ -c timer.cpp

clean:
	rm *.o
