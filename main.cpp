#include"Sudoku.h"

int main()
{
	Sudoku ss;
	ss.readIn();
	ss.changeRow(1, 2);
	ss.solve();
}
