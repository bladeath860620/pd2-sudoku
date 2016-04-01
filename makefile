all:
	g++ sudoku.cpp giveQuestion.cpp -o q
	g++ sudoku.cpp transform.cpp -o t
	g++ sudoku.cpp solve.cpp -o s