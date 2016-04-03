all:
	g++ Sudoku.cpp giveQuestion.cpp -o q
	g++ Sudoku.cpp transform.cpp -o t
	g++ Sudoku.cpp solve.cpp -o s