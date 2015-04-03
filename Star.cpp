#include<iostream.h>
#include<stdlib.h>
#include<time.h>

char Board[10][10]=
	{
		'+','+','+','+','+','+','+','+','+',' ',
		'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};

class Starlight
{
private:
	int numstars;
public:
	Starlight();
	void Intro();
	void Placestars();
	void Countem();
	void Showboard();
	void Clearboard();
};


Starlight::Starlight()
{
	numstars=0;
}


void Starlight::Intro()
{
	cout<<" ________________________________________________________ "<<endl;
	cout<<"| Welcome to Starlight                                   |"<<endl;
	cout<<"|--------------------------------------------------------|"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"| Good luck                                              |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;
	system("pause");
	system("cls");

}

void Starlight::Placestars()
{
	for (int a=1;a<9;a++)
	{
		for (int b=1;b<9;b++)
		{
			int temp=rand()%8;

			if (temp<2)
				Board[a][b]=48;
			else
			{
				int temp=rand()%9+48; 
				Board[a][b]=temp;
			}

		}
		cout<<endl;
	}
}

void Starlight::Countem()
{
	for (int a=1;a<9;a++)
	{
		for (int b=1;b<9;b++)
		{
			int temp=0;

			if(a==1 && b==1)
				temp=(Board[a][b]+Board[a][b+1]+Board[a+1][b])-(48*3);
			else if(a==1 && b==8)
				temp=(Board[a][b]+Board[a][b-1]+Board[a+1][b])-(48*3);
			else if(a==8 && b==1)
				temp=(Board[a][b]+Board[a-1][b]+Board[a][b+1])-(48*3);
			else if(a==8 && b==8)
				temp=(Board[a][b]+Board[a][b-1]+Board[a-1][b])-(48*3);

			else if(a==1 && b!=1 && b!=8)
				temp=(Board[a][b]+Board[a][b-1]+Board[a][b+1]+Board[a+1][b])-(48*4);
			else if(a==8 && b!=8 && b!=1)
				temp=(Board[a][b]+Board[a][b-1]+Board[a][b+1]+Board[a-1][b])-(48*4);
			else if(a!=8 && a!=1 && b==1)
				temp=(Board[a-1][b]+Board[a+1][b]+Board[a][b+1]+Board[a][b])-(48*4);
			else if(a!=8 && a!=1 && b==8)
				temp=(Board[a-1][b]+Board[a+1][b]+Board[a][b-1]+Board[a][b])-(48*4);

			else
				int temp=(Board[a][b]+Board[a-1][b]+Board[a+1][b]+Board[a][b+1]+Board[a][b-1])-(48*5);

				
			if(temp/5>2)
			{
				Board[a][b]='*';
				numstars++;
			}
	
		}
	}
	cout<<numstars<<" stars found"<<endl;
}

void Starlight::Showboard()
{
	for (int a=0;a<10;a++)
	{
		for (int b=0;b<10;b++)
		{
			cout<<Board[a][b]<<" ";
		}
		cout<<endl;
	}

}

void Starlight::Clearboard()
{
	for (int a=0;a<10;a++)
	{
		for (int b=0;b<10;b++)
		{
			if (Board[a][b]!='*' && Board[a][b]!='+')
			{
				Board[a][b]=' ';
			}
		}
	}

}

int main()
{
srand(time(0));

Starlight thissearch;

thissearch.Intro();
thissearch.Placestars();
system("cls");
thissearch.Showboard();
thissearch.Countem();
cout<<endl;
thissearch.Clearboard();
thissearch.Showboard();


	return 0;
}