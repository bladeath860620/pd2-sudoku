all: Sudoku.o giveQuestion.cpp solve.cpp transform.cpp
	g++ -o giveQuestion giveQuestion.cpp Sudoku.o -Wall
	g++ -o solve solve.cpp Sudoku.o -Wall
	g++ -o transform transform.cpp Sudoku.o -Wall

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o -Wall
