/*********************
	Compiler Theory
	ex2: NFA -> DFA
	(subset construction)

	DFAtable.h
		- implement class DFAtable

	1427405017
	Éò¼ÒÚS
*********************/
#ifndef  DFA_TABLE
#define DFA_TABLE

#include <iostream>
#include <string>

#define DFA_MAX_ROW 20
#define DFA_MAX_COLUMN 20

using namespace std;

class NFAtable;
class DFAtable{
private:
	char meta[NFA_MAX_COLUMN];		// column meta data : input type
	int Dtran[DFA_MAX_ROW][NFA_MAX_COLUMN];	// Dtran
	string tag[DFA_MAX_ROW];				// tag the Dstates
	string Dstates[DFA_MAX_ROW][NFA_MAX_ROW];
	int row_count;		// count actual row
	int col_count;		// count actual col
	int unTagged_count;	// count unTagged Dstates
public:
	DFAtable()
	{
		row_count = 0;
		col_count = 0;
		unTagged_count = 0;
	}
	DFAtable(NFAtable nfa)
	{
		row_count = 0;
		unTagged_count = 0;
		col_count = nfa.getColCount()-1;
		strcpy(meta, nfa.getColMeta());
	}
	vector<string> getNodesInState(string T)
	{
		int i;
		for( i=0; i<row_count-unTagged_count; i++)
		{
			if(tag[i] == T)
			{
				break;
			}
		}
		vector<string> vec;
		for(int j=0; !Dstates[i][j].empty(); j++)
		{
			vec.push_back(Dstates[i][j]);
		}
		return vec;
	}
	int getUnTaggedCount()
	{
		return unTagged_count;
	}
/*
	string completeTag()
	function: complete the tag of the first unTagged Dstate
	input: none
	output: newly completed Tag
*/
	string completeTag()
	{
		char tag_t = ('A'+row_count-unTagged_count);
		tag[row_count-unTagged_count] = tag_t;	// completed the untagged state
		unTagged_count--;
		return tag[row_count-unTagged_count-1];
	}
/*
	int isExistInDFA(vector<string> vec)
	function: return the corresponding row's index in Dstates
	input: vector<string>
	output: the corresponding row's index in Dstates
				return -1 for not exist !
*/
	int isExistInDFA(vector<string> vec)
	{
		int i, j, k, l;
		vector<string> vec_t;
		for( j=0; j<row_count; j++)
		{
			vec_t.clear();
			for( k=0; !Dstates[j][k].empty(); k++)
			{
				vec_t.push_back(Dstates[j][k]);
			}

			for( k=0; k<vec.size(); k++)		// for every node in vec
			{
				for( l=0; l<vec_t.size(); l++)		// check vec_t
				{
					if(vec[k] == vec_t[l])
					{
						break;
					}
				}
				if( l == vec_t.size() )		// if vec[k] not exists in vec_t
				{
					break;
				}
			}
			if( k == vec.size() && vec.size() == vec_t.size())		// if every node in vec is found in vec_t and size equal
			{
				return j;
			}
		}
		return -1;
	}

/*
	int addUnTaggedState(vector<string> vec)
	function : add a vector of nodes to Dstate and keep untagged
	input: vector<string>
	output: the row's index of newly vec input in Dstate
*/
	int addUnTaggedState(vector<string> vec)
	{
		for(int k=0; k<vec.size(); k++)
		{
			Dstates[row_count][k] = vec[k];
		}
		tag[row_count] = "Untag";
		unTagged_count++;
		row_count++;
		cout<<"row_count: "<<row_count<<endl;
		cout<<"unTagged_count:"<<unTagged_count<<endl;
		return row_count-1;
	}

/*
	void addDtranEntry(string T, char a, int U_idx)
	function: Dtran[T, a] = U;
	input: row - string T;
				col - char a;
				entry - U_idx;
	output: none
*/
	void addDtranEntry(string T, char a, int U_idx)
	{
		int row_index;
		for(row_index=0; row_index<(row_count-unTagged_count); row_index++)
		{
			if(tag[row_index] == T)
			{
				break;
			}
		}
		if( row_index == (row_count-unTagged_count) )
		{
			cerr<<"ERROR: addDtranEntry can't find corresponding state"<<endl;
			exit(0);
		}
		int col_index;
		for(col_index=0; col_index<col_count; col_index++)
		{
			if(meta[col_index] == a)
			{
				break;
			}
		}
		if(col_index==col_count)
		{
			cerr<<"ERROR: addDtranEntry can't find corresponding input char"<<endl;
			exit(0);
		}
		//string temptag_U = completeTag();
		//unTagged_count++;	// recover unTagged_count, because temptag_U is for temp use
		Dtran[row_index][col_index] = U_idx;
		
	}
/*
	void show()
	function: print the DFA Dtran table on the console screen
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
			cout<<"| "<<tag[i]<<" "<<"|";
			for(int j=0; j<col_count; j++)
			{
				cout<<"\t";
				cout<<tag[ Dtran[i][j] ]<<' ';
			}
			cout<<endl;
		}
	}

	friend vector<string> e_closure_s(string state, NFAtable &nfa, DFAtable &dfa);
	friend vector<string> move(string T, char a, NFAtable &nfa, DFAtable &dfa);
	friend vector<string> e_closure_T(vector<string> vec, NFAtable &nfa, DFAtable &dfa);
};

#endif