# include<iostream>
# include <fstream>
//# include <vector>
# include"Life.h"
using namespace std;

int Life::neighbor_count(int row,int col)
{
	int i,j;
	int count=0;
	for(i=row-1;i<=row+1;i++)
		for(j=col-1;j<=col+1;j++)
			count+=grid[i][j];
		
	count-=grid[row][col];
	return count;
}
//-------------------------------------------------------------------------------
void Life::update()			//update the whole configuration
{
	int row,col;
	int new_grid[maxrow+2][maxcol+2];

	for(row=1;row<=maxrow;row++)			//create a new grid
		for(col=1;col<=maxcol;col++)
			switch(neighbor_count(row,col))
			{
				case 2:
					new_grid[row][col]=grid[row][col];
					break;
				case 3:
					new_grid[row][col]=1;
					break;
				default:
					new_grid[row][col]=0;
			}

	for(row=1;row<=maxrow;row++)
		for(col=1;col<=maxcol;col++)
			grid[row][col]=new_grid[row][col];		//replace the gird with new_grid
}
//-------------------------------------------------------------------------------
//void Life::initialize()		// the life object contains a configuration specified by the user
//{
//	int row,col;
//	for(row=0;row<=maxrow+1;row++)
//		for(col=0;col<=maxcol+1;col++)
//			grid[row][col]=0;
//
//	cout<<"List the coordinates for living cells"<<endl;
//	cout<<"Terminate the list with the special pair -1 -1"<<endl;
//	cin>>row>>col;
//	while(row!=-1||col!=-1)
//	{
//		if(row>=1 && row <=maxrow)
//			if(col>=1 && col<=maxcol)
//				grid[row][col]=1;
//			else
//				cout<<"Column "<<col<<" is out of range."<<endl;
//		else
//			cout<<"Row "<<row<<" is out of range."<<endl;
//
//		cin>>row>>col;
//	}
//}

void Life::initialize()		// new version 1 : read from keyboard or file directly.
{
	int row, col;
	char in_choice, temp;

	for(row=0;row<=maxrow+1;row++)
	{
		for(col=0;col<=maxcol+1;col++)
		{
			grid[row][col] = 0;		// set default value as 0
		}
	}

	cout<<"input K to read from keyboard"<<endl;
	cout<<"input F to read from file(in.txt)"<<endl;
	do
	{
		in_choice = cin.get();
	}while(in_choice!='K' && in_choice != 'k' && in_choice!= 'F' && in_choice != 'f');		// to get the effective order

	if(in_choice == 'K' || in_choice == 'k')		//read from keyboard
	{
		cout<<"start input with space, x and Enter, input else character to end"<<endl;

		for(row=1;row<=maxrow;row++)
		{
			for(col=1;col<=maxcol;col++)
			{
				temp = cin.get();

				if(temp==' ')
				{
					continue;		// if the user inputs Space, then skip the spot and leave it as 0.
				}
				else if(temp=='x' || temp=='X')
				{
					grid[row][col] = 1;	// if the user inputs x or X, then mark the spot 1.
				}
				else if(temp=='\n')
				{
					break;	// if the user inputs Enter, then break the inner loop and switch to the next row.
				}
				else
				{
					return;	// if the user inputs other value, then end initializing.
				}
			}
		}
	}
	else if(in_choice == 'F' || in_choice == 'f')							//read from file
	{
		cout<<"start input from a file(in.txt).\nIt will recognize space, x and Enter, else character will lead to end"<<endl;

		ifstream fin;
		fin.open("in.txt");

		for(row=1;row<=maxrow;row++)
		{
			for(col=1;col<=maxcol;col++)
			{
				//fin>>temp;
				fin.get(temp);

				if( !fin.eof() )	// if fin does not touch the end of the file, then keep initializing.
				{
					if(temp==' ')
					{
						continue;		// if the user inputs Space, then skip the spot and leave it as 0.
					}
					else if(temp=='x' || temp=='X')
					{
						grid[row][col] = 1;	// if the user inputs x or X, then mark the spot 1.
					}
					else if(temp=='\n')
					{
						break;	// if the user inputs Enter, then break the inner loop and switch to the next row.
					}
					else
					{
						return;	// if the user inputs other value, then end initializing.
					}
				}
				else	// if fin touches the end of the file, then end intializng.
				{
					return;
				}
			}
		}
		fin.close();
	}
}


//void Life::initialize()		// new version 2 : initialize without boundary by using dynamic vector
//{
//	int row, col;
//	char in_choice, temp;
//
//	do
//	{
//		cout<<"input K to read from keyboard"<<endl;
//		cout<<"input F to read from file(in.txt)"<<endl;
//
//		in_choice = cin.get();
//	}while(in_choice!='K' && in_choice != 'k' && in_choice!= 'F' && in_choice != 'f');		// to get the effective order
//
//	if(in_choice == 'K' || in_choice == 'k')		//read from keyboard
//	{
//		cout<<"start input with space, x and Enter, input else character to end"<<endl;
//		
//		vector<string> input;
//		while(cin.)
//		input.push_back(cin>>);
//	
//		temp = cin.get();
//
//		if(temp==' ')
//		{
//			_grid[1].push_back(0);
//			//continue;		// if the user inputs Space, then skip the spot and leave it as 0.
//		}
//		else if(temp=='x' || temp=='X')
//		{
//			grid[row][col] = 1;	// if the user inputs x or X, then mark the spot 1.
//		}
//		else if(temp=='\n')
//		{
//			break;	// if the user inputs Enter, then break the inner loop and switch to the next row.
//		}
//		else
//		{
//			return;	// if the user inputs other value, then end initializing.
//		}
//	}
//	else if(in_choice == 'F' || in_choice == 'f')							//read from file
//	{
//		cout<<"start input from a file(in.txt).\nIt will recognize space, x and Enter, else character will lead to end"<<endl;
//
//		ifstream fin;
//		fin.open("in.txt");
//
//		for(row=1;row<=maxrow;row++)
//		{
//			for(col=1;col<=maxcol;col++)
//			{
//				//fin>>temp;
//				fin.get(temp);
//
//				if( !fin.eof() )	// if fin does not touch the end of the file, then keep initializing.
//				{
//					if(temp==' ')
//					{
//						continue;		// if the user inputs Space, then skip the spot and leave it as 0.
//					}
//					else if(temp=='x' || temp=='X')
//					{
//						grid[row][col] = 1;	// if the user inputs x or X, then mark the spot 1.
//					}
//					else if(temp=='\n')
//					{
//						break;	// if the user inputs Enter, then break the inner loop and switch to the next row.
//					}
//					else
//					{
//						return;	// if the user inputs other value, then end initializing.
//					}
//				}
//				else	// if fin touches the end of the file, then end intializng.
//				{
//					return;
//				}
//			}
//		}
//		fin.close();
//	}
//}
//-------------------------------------------------------------------------------

void Life::print()		// print the whole configuration
{
	int row,col;
	cout<<"\nThe current Life configuration is:"<<endl;
	for(row=1;row<=maxrow;row++)
	{
		for(col=1;col<=maxcol;col++)
			if(grid[row][col]==1)cout<<"*";
			else cout<<" ";

		cout<<endl;
	}
	cout<<endl;
}

//------------------------------------------------------------------------------------