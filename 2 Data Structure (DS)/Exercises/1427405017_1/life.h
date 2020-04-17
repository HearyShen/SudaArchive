# include<iostream>
//# include<vector> 
using namespace std;

const int maxrow=20,maxcol=60;

class Life
{
public:
	void initialize();
	void print();
	void update();
private:
	int grid[maxrow+2][maxcol+2];		//allow for two extra rows and columns
	//vector<vector<int>> _grid;
	int neighbor_count(int row,int col);
};