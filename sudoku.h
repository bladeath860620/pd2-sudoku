#ifndef SUDOKU
#define SUDOKU
class Sudoku
{
	public:
		void giveQuestion();
		void readIn();
		void changeNum(int , int);
		void changeRow(int , int);
		void changeCol(int , int);
		void rotate(int);
		void flip(int);
		void transform();
		void sudo_print();
		//void blanking();
		void solve();
		void question_trans();
		void BT();
	//private:
};
#endif