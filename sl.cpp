#include<iostream.h>
#include<string.h>
#include<iomanip.h>
#include<stdlib.h>

void showboard();

int board[8][6]=
{
	'0','3','4','0','0','0','6','8',
	'5','13','6','0','0','0','2','3',
	'2','6','2','7','3','0','10','0',
	'0','0','4','15','4','1','6','0',
	'0','0','7','12','6','9','10','4',
	'5','0','6','10','6','4','8','0'
};

int main()
{
showboard();
return 0;
}

void showboard()
{
	for (int a=0;a<6;a++)
	{
		for (int b=0;b<8;b++)
		{
			cout<<board[a][b]<<"  ";
		}
		cout<<endl;
	}
}