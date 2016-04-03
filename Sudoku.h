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
		void BT(int , int);
		void set_zero(int,int,int);
		bool check(int,int,int);
		void check_bool(int,int);
	//private:
};
#endif
/*
0 0 0 0 0 8 0 4 7   
3 0 0 0 0 7 0 0 0   
0 0 2 0 0 0 0 0 0   
0 0 0 3 9 0 0 0 0   
0 0 0 2 0 0 0 0 0   
0 8 0 0 0 0 0 5 0   
0 4 0 0 0 1 0 0 0   
0 0 0 0 0 0 2 0 9   
0 0 0 7 0 0 0 0 5
*/
/*
6 9 1 5 2 8 3 4 7 
3 5 8 4 1 7 9 2 6 
4 7 2 6 3 9 5 8 1 
1 2 5 3 9 6 8 7 4 
7 6 4 2 8 5 1 9 3 
9 8 3 1 7 4 6 5 2 
2 4 6 9 5 1 7 3 8 
5 1 7 8 4 3 2 6 9 
8 3 9 7 6 2 4 1 5
*/
/*
1 2 3 4 5 6 7 8 9 
4 5 6 7 8 9 1 2 3 
7 8 9 1 2 3 4 5 6
2 3 1 5 6 4 8 9 7
5 6 4 8 9 7 2 3 1 
8 9 7 2 3 1 5 6 4 
3 1 2 6 4 5 9 7 8 
6 4 5 9 7 8 3 1 2 
9 7 8 3 1 2 0 0 0
*/ 