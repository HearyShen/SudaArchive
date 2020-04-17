/*********************
	Compiler Theory
	ex2: NFA -> DFA
	(subset construction)

	NFAtable.h
		- implement class DFAtable

	1427405017
	Éò¼ÒÚS
*********************/
#ifndef NFA_TABLE
#define NFA_TABLE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define NFA_MAX_ROW 20
#define NFA_MAX_COLUMN 20
#define NFA_MAX_PER 10

using namespace std;

class DFAtable;
class NFAtable{
private:
	string str[NFA_MAX_ROW];			// raw lines in input file
	char meta[NFA_MAX_COLUMN];	// column meta data
	string entry[NFA_MAX_ROW][NFA_MAX_COLUMN][NFA_MAX_PER];	// dest entry[] in all row and col
	int row_count, col_count;				// actual row and col count
public:
	NFAtable()
	{
		row_count = 0;
		col_count = 0;
	}

/*
	NFAtable(ifstream fin)
	function: constructor of class NFAtable with ifstream fin
	input: fin
	output: object instance of NFAtable
*/
	NFAtable(ifstream fin)
	{
		cout<<"constructing NFAtable..."<<endl;
		row_count = 0;
		col_count = 0;
		
		
		string str_meta;
		getline(fin, str_meta);
		istringstream meta_in(str_meta);

		meta_in>>row_count;
		cout<<"NFA state:"<<row_count<<endl;
		
		/* read meta data - column */
		char char_t;
		while( !meta_in.eof() )
		{
			char_t = meta_in.get();
			switch( char_t )
			{
			case ',': break;
			case ' ': break;
			case -1: break;
			default: 
				meta[col_count] = char_t;
				//cout<<meta[col_count]<<"\t";
				col_count++;
				break;
			}
		}
		//cout<<endl;

		/* read entry data - rows  */
		int i = 0;
		int j = 0;
		int k = 0;
		while( !fin.eof() )
		{
			getline(fin, str[i]);
			j = 0;
			k = 0;
			//cout<<i<<"\t"<<str[i]<<endl;
			istringstream entry_in(str[i]);
			while( !entry_in.eof() )
			{
				char_t = entry_in.get();
				switch(char_t)
				{
				case ' ': break;
				case ';': 
					//cout<<"\t"<<entry[i][j];
					j++;
					k = 0;
					break;
				case ',':
					k++;
					break;
				case -1:
					break;
				default: 
					entry[i][j][k] += char_t;
					break;
				}
				
			}
			//cout<<endl;
			
			i++;
		}
	}

/*
	void show()
	function: print the NFA table on the console screen
	input: none
	output: none
*/
	void show()
	{
		for(int j=0; j<col_count; j++)
		{
			cout<<"\t"<<meta[j];
		}
		cout<<endl;
		for(int j=0; j<10*col_count; j++)
		{
			cout<<"-";
		}
		cout<<endl;
		for(int i=0; i<row_count; i++)
		{
			cout<<"| "<<i<<" "<<"|";
			for(int j=0; j<col_count; j++)
			{
				cout<<"\t";
				for(int k=0; !entry[i][j][k].empty(); k++)
				{
					cout<<entry[i][j][k]<<' ';
				}
			}
			cout<<endl;
		}
	}

	
	int getRowCount()
	{
		return row_count;
	}
	int getColCount()
	{
		return col_count;
	}
	char* getColMeta()
	{
		return meta;
	}
	vector<string> getDestNodes(int row, char col)
	{
		int i = row;
		int j;
		for(j=0; j<col_count; j++)
		{
			if(meta[j] == col)
			{
				break;
			}
		}
		vector<string> vec_str;
		for(int k=0; !entry[i][j][k].empty(); k++)
		{
			if(entry[i][j][k] == "void")
			{
				continue;
			}
			vec_str.push_back(entry[i][j][k]);
		}
		return vec_str;
	}

	friend vector<string> e_closure_s(string state, NFAtable &nfa, DFAtable &dfa);
	friend vector<string> move(string T, char a, NFAtable &nfa, DFAtable &dfa);
	friend vector<string> e_closure_T(vector<string> vec, NFAtable &nfa, DFAtable &dfa);
};

#endif