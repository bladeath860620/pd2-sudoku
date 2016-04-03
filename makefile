all:
	g++ Sudoku.cpp giveQuestion.cpp -o q -g
	g++ Sudoku.cpp transform.cpp -o t -g
	g++ Sudoku.cpp solve.cpp -o s -g