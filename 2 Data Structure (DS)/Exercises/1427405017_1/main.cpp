#include"utility.h"
#include"Life.h"

void instructions();

void main()
{
	Life configuration;
	instructions();
	configuration.initialize();
	configuration.print();
	cout<<"Continue viewing new generations?"<<endl;
	while(user_says_yes())
	{
		configuration.update();
		configuration.print();
		cout<<"Continue viewing new generations?"<<endl;
	}	
}

void instructions()
{
	cout<<"Welcome to Conway's game of Life."<<endl;
	cout<<"This game uses a grid of size"<<maxrow<<" by "<<maxcol<<" in which "<<endl;
	cout<<"each cell can either be occupied by an organism or not."<<endl;
	cout<<"The occupied cells change from generation to generation"<<endl;
	cout<<"according to the nubers of neighboring cells which are alive"<<endl;
}