#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Sudoku.h"

using namespace std;

int su[9][9];
int su2[9][9] = {{0}};
int su3[9][9][10]; 
bool have_zero = false;
int x, y;
int ans[9][9]={{0}};
int ans_count = 0;

bool Sudoku::check(int i, int j, int k)
{
	int a, b, i3, j3;
	i3 = (i/3)*3;
	j3 = (j/3)*3;
	for(a=i3; a<=i3+2; a++)
	{
		for(b=j3; b<=j3+2; b++)
		{
			if(a!=i && b!=j)
			{
				if(su3[a][b][0] == k)
					return false;
			}
		}
	}
	for(a=0; a<9; a++)
	{
		if(a!=j)
		{
			if(su3[i][a][0] == k)
				return false;
		}
		if(a!=i)
		{
			if(su3[a][j][0] == k)
				return false;
		}
	}
	return true;
}

void Sudoku::BT(int i, int j)
{
	int k;
	int a, b;
	int m,n;
	if(ans_count == 2)
		return;
	for(k=1; k<10; k++)
	{
		if(check(i,j,k))
		{
			su3[i][j][0] = k;
			m = i;
			n = j;
			while(su3[m][n][0] != 0)
			{
				n++;
				if(n==9)
				{
					n=0;
					m++;
				}
				if(m==9)
					break;
			}
			if(m==9)
			{
				ans_count++;
				for(a=0; a<9; a++)
				{
					for(b=0 ;b<9; b++)
					{
						ans[a][b] = su3[a][b][0];
					}
				}
			}
			else
				BT(m ,n);
			su3[i][j][0] = 0;
		}
		else if(k == 9 && check(i,j,k) == false)
			return;
	}
}

void Sudoku::set_zero(int i, int j, int k)
{
	int a, b, i3, j3;
	i3 = (i/3)*3;
	j3 = (j/3)*3;
	for(a=i3; a<=i3+2; a++)
	{
		for(b=j3; b<=j3+2; b++)
		{
			su3[a][b][k] = 0;
		}
	}
	for(a=0; a<9; a++)
	{
		su3[i][a][k] = 0;
		su3[a][j][k] = 0;
	}
	for(b=1; b<10; b++)
	{
		su3[i][j][b] = 0;
	}
}

void Sudoku::solve()
{
	int i, j, k;
	int n;
	
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			su3[i][j][0] = su[i][j];
		}
	}
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			for(k=1; k<10; k++)
			{
				su3[i][j][k] = 1;
			}
		}
	}
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			n = su3[i][j][0];
			if(n != 0)
			{
				if(su3[i][j][n] == 0)
				{
					cout << '0' << endl;
					return;
				}
				set_zero(i,j,n);
			}
		}
	}
	for(i=0; i<9; i++)
	{
		for(j=0; j<9 ;j++)
		{
			if(su3[i][j][0] == 0)
			{
				if(have_zero == false)
				{
					have_zero = true;
					x = i;
					y = j;
				}
			}
			if(i==8 && j==8 && have_zero == false)
			{
				ans_count = 1;
				cout << '1' << endl;
				sudo_print();
			}
			su[i][j] = su3[i][j][0];
		}
	}
	if(have_zero == true)
	{
		BT(x, y);
	}
	if(ans_count == 1 && have_zero == true)
	{
		for(i=0; i<9; i++)
		{
			for(j=0; j<9 ;j++)
			{
				su[i][j] = ans[i][j];
			}
		}
		cout << '1' << endl;
		sudo_print();
	}
	else if(ans_count == 2)
	{
		cout << '2' << endl;
	}
	else if(ans_count == 0)
		cout << '0'<< endl;
}

void Sudoku::sudo_print()
{
	int i, j;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			cout << su[i][j] << " ";
			if(j==8)
				cout << endl;
		}
	}
}

void Sudoku::giveQuestion()
{
	int n;
	int i, j;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			su[i][j] = 0;
		}
	}
	srand(time(NULL));
	n = rand() % 10;
	switch(n)
	{
		case 0:
			su[0][5]=6;su[0][6]=8;su[0][8]=7;su[2][0]=5;
			su[2][2]=4;su[2][6]=3;su[3][3]=7;su[3][5]=8;
			su[3][6]=6;su[4][0]=9;su[4][4]=4;su[4][7]=5;
			su[6][4]=9;su[6][7]=2;su[7][1]=6;su[7][2]=8;
			su[8][7]=4;
			break;
		case 1:
			su[0][4]=5;su[0][7]=9;su[1][0]=4;su[1][8]=2;
			su[2][2]=6;su[2][3]=7;su[3][0]=2;su[4][0]=9;
			su[4][1]=5;su[4][7]=1;su[5][3]=6;su[6][8]=3;
			su[7][1]=8;su[7][6]=7;su[7][8]=6;su[8][4]=1;
			su[8][5]=3;
			break;
		case 2:
			su[0][4]=4;su[1][1]=3;su[1][6]=6;su[1][8]=8;
			su[2][3]=5;su[2][4]=2;su[3][0]=9;su[3][2]=5;
			su[4][2]=2;su[5][5]=6;su[5][6]=8;su[6][0]=1;
			su[6][4]=9;su[6][7]=5;su[8][1]=8;su[8][5]=4;
			su[8][6]=3;
			break;
		case 3:
			su[0][4]=5;su[0][7]=2;su[0][8]=1;su[1][0]=4;
			su[2][7]=5;su[4][1]=2;su[4][3]=7;su[5][3]=8;
			su[5][5]=3;su[5][6]=4;su[6][1]=5;su[6][2]=9;
			su[6][4]=2;su[7][3]=4;su[7][6]=8;su[7][8]=3;
			su[8][1]=1;
			break;
		case 4:
			su[0][5]=5;su[0][7]=2;su[1][0]=1;su[1][3]=9;
			su[2][0]=4;su[3][2]=8;su[3][5]=2;su[4][8]=1;
			su[5][6]=9;su[5][8]=4;su[6][2]=5;su[6][6]=3;
			su[7][3]=1;su[7][8]=7;su[8][2]=2;su[8][3]=4;
			su[8][5]=8;
			break;
		case 5:
			su[1][1]=5;su[1][5]=1;su[2][3]=6;su[2][6]=7;
			su[2][7]=8;su[3][0]=8;su[3][3]=7;su[3][7]=6;
			su[5][1]=3;su[5][8]=5;su[6][0]=7;su[6][2]=6;
			su[6][7]=4;su[7][1]=9;su[7][5]=5;su[7][8]=1;
			su[8][5]=3;
			break;
		case 6:
			su[0][1]=2;su[0][5]=6;su[1][6]=4;su[2][0]=3;
			su[2][6]=8;su[3][3]=8;su[4][1]=6;su[4][7]=7;
			su[5][0]=9;su[5][3]=4;su[5][6]=3;su[6][2]=1;
			su[6][5]=7;su[6][7]=6;su[7][7]=2;su[8][0]=4;
			su[8][3]=3;
			break;
		case 7:
			su[0][2]=5;su[0][8]=9;su[2][0]=7;su[2][3]=6;
			su[2][6]=1;su[3][5]=4;su[4][4]=5;su[4][5]=9;
			su[4][8]=3;su[5][0]=2;su[5][7]=7;su[6][2]=9;
			su[6][5]=8;su[7][3]=7;su[7][6]=2;su[7][7]=6;
			su[8][2]=4;
			break;
		case 8:
			su[0][5]=8;su[0][7]=4;su[0][8]=7;su[1][0]=3;
			su[1][5]=7;su[2][2]=2;su[3][3]=3;su[3][4]=9;
			su[4][3]=2;su[5][1]=8;su[5][7]=5;su[6][1]=4;
			su[6][5]=1;su[7][6]=2;su[7][8]=9;su[8][3]=7;
			su[8][8]=5;
			break;
		case 9:
			su[0][2]=1;su[0][5]=8;su[0][7]=9;su[1][1]=4;
			su[1][8]=5;su[3][4]=9;su[3][8]=7;su[4][2]=2;
			su[4][5]=3;su[5][2]=8;su[5][6]=6;su[6][1]=7;
			su[6][4]=5;su[7][5]=2;su[7][6]=8;su[8][1]=5;
			su[8][7]=4;
			break;
	}
	transform();
}

void Sudoku::readIn()
{
	int i, j;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			scanf("%d", &su[i][j]);
		}
	}
}

void Sudoku::transform()
{
	srand(time(NULL));
	int i;
	int n1, n2, n3, n4, n5, n6, n7, n8;
	for(i=0; i<44; i++)
	{
		n1 = rand() % 9+1;
		n2 = rand() % 9+1;
		while(n2 == n1)
			n2 = rand() % 9+1;
		changeNum(n1, n2);
	}
	n3 = rand() % 2;
	flip(n3);
	n4 = 3;
	rotate(n4);
	n5 = rand() % 3;
	n6 = rand() % 3;
	while(n6 == n5)
		n6 = rand() % 3;
	changeRow(n5, n6);
	n7 = rand() % 3;
	n8 = rand() % 3;
	while(n8 == n7)
		n8 = rand() % 3;
	changeCol(n7, n8);
	sudo_print();
}

void Sudoku::changeNum(int a, int b)
{
	int i, j;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			if(su[i][j] == a)
				su[i][j] = b;
			else if(su[i][j] == b)
				su[i][j] = a;
		}
	}
}

void Sudoku::flip(int n)
{
	int i ,j;
	if(n==0)
	{
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				su2[i][8-j] = su[i][j];
			}
		}
	}
	else if(n==1)
	{
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				su2[8-i][j] = su[i][j];
			}
		}
	}
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			su[i][j] = su2[i][j];
		}
	}
}

void Sudoku::rotate(int n)
{
	int i, j;
	n = n%4;
	if(n == 0)
		return;
	else if(n==1)
	{
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				su2[i][j] = su[8-j][i];
			}
		}
	}
	else if(n==2)
	{
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				su2[8-i][8-j] = su[i][j];
			}
		}
	}
	else if(n==3)
	{
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				su2[i][j] = su[j][8-i];
			}
		}
	}	
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			su[i][j] = su2[i][j];
		}
	}
}

void Sudoku::changeCol(int a, int b)
{
	int i, j;
	int temp;
	int n;
	if(a>b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	n = 3*(b-a);
	for(i = 0; i < 9; i++)
	{
		for(j = a*3;j < a*3+3; j++)
		{
			temp = su[i][j];
			su[i][j] = su[i][j+n];
			su[i][j+n] = temp;
		}
	}
}

void Sudoku::changeRow(int a, int b)
{
	int i, j;
	int temp;
	int n;
	if(a>b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	n = 3*(b-a);
	for(i = a * 3; i < a*3+3; i++)
	{
		for(j = 0; j < 9; j++)
		{
			temp = su[i][j];
			su[i][j] = su[i+n][j];
			su[i+n][j] = temp;
		}
	}
}