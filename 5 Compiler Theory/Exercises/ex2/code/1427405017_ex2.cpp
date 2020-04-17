/*********************
	Compiler Theory
	ex2: NFA -> DFA
	(subset construction)

	1427405017_ex2.cpp
		- main file

	1427405017
	Éò¼ÒÚS
*********************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "NFAtable.h"
#include "DFAtable.h"

using namespace std;

vector<string> e_closure_s(string node, NFAtable &nfa, DFAtable &dfa)
{
	stack<string> stk;

	stk.push(node);

	vector<string> T;
	T.push_back(node);

	string str_t;
	vector<string> vec_t;
	int j, k;
	while( !stk.empty() )
	{
		str_t = stk.top();		// get the top node in stack
		stk.pop();					// pop out the top node
		vec_t = nfa.getDestNodes(atoi(str_t.c_str()), 'e');
		for( j=0; j<vec_t.size(); j++)		// every node from str_t through e ,(if exists)
		{
			for( k=0; k<T.size(); k++)
			{
				if(vec_t[j] == T[k])
				{
					break;
				}
			}
			if( k == T.size())			// new node ( not repeated in T)
			{
				T.push_back( vec_t[j] );
				stk.push( vec_t[j] );
			}
		}
	}
	for(int k=0; k<T.size(); k++)
	{
		dfa.Dstates[dfa.row_count][k] = T[k];
	}
	dfa.unTagged_count++;
	dfa.row_count++;
	return T;
}

vector<string> move(string T, char a, NFAtable &nfa, DFAtable &dfa)
{
	int i, j, k, l;
	vector<string> vec_dest, vec_t;
	string str_t;
	for(i=0; i<dfa.row_count; i++)		// find the row number i corresponding to state T
	{
		if(dfa.tag[i] == T)
		{
			break;
		}
	}
	for( j=0; !dfa.Dstates[i][j].empty(); j++)		// traverse all nodes in state T
	{
		if(dfa.Dstates[i][j] == "void")
		{
			break;
		}
		int from = atoi( dfa.Dstates[i][j].c_str() );	// get node's index
		vec_t = nfa.getDestNodes( from, a);	// get node's dests through input char a
		/* 
			following:
				merge current node's dests(vec_t) into vec_dest;
				( remove repeated ones )
		*/
		for( k=0; k<vec_t.size(); k++)		// for every node in vec_t, 
		{
			if( vec_t[k] == "void")		// ignore "void" dest node
			{
				continue;
			}
			for( l=0; l<vec_dest.size(); l++)		// check vec_dest to avoid repeated node
			{
				if(vec_t[k] == vec_dest[l])
				{
					break;
				}
			}
			if( l == vec_dest.size() )		// if new dest node, then add to vec_dest
			{
				vec_dest.push_back(vec_t[k]);
			}
		}

	}
	return vec_dest;
}

vector<string> e_closure_T(vector<string> vec, NFAtable &nfa, DFAtable &dfa)
{
	stack<string> stk;

	for(int i=0; i<vec.size(); i++)		// push all nodes in state T into stack
	{
		stk.push(vec[i]);
	}

	vector<string> T = vec, vec_t;
	string str_t;
	int j, k;
	while( !stk.empty() )
	{
		str_t = stk.top();		// get the top node in stack
		stk.pop();					// pop out the top node
		vec_t = nfa.getDestNodes(atoi(str_t.c_str()), 'e');
		for( j=0; j<vec_t.size(); j++)		// every node(if exists) from str_t through e
		{
			for( k=0; k<T.size(); k++)
			{
				if(vec_t[j] == T[k])
				{
					break;
				}
			}
			if( k == T.size())			// new node ( not repeated in T)
			{
				T.push_back( vec_t[j] );
				stk.push( vec_t[j] );
			}
		}
	}

	return T;
}

/*
	ifstream readFile(char filepath[])
	function: create ifstream from filepath
	input: char filepath[] - url of input file
	output: ifstream - temporary ifstream object
*/
ifstream readFile(char filepath[])
{
	ifstream file_in(filepath);
	if(file_in == NULL)
	{
		cerr<<"ERROR: failed to open the file !"<<endl;
		exit(0);
	}

	return file_in;
}

void printVec(vector<string> vec)
{
	for(int j=0; j<vec.size(); j++)
		cout<<vec[j]<<" ";
	cout<<endl;
}

int main()
{
	char filepath_in[] = "NFA_0.txt";

	/* 1. read file and parse NFAtable instance */
	cout<<"Reading file : "<<filepath_in<<endl;
	NFAtable nfa( readFile(filepath_in) );
	nfa.show();
	cout<<"NFA input type count: "<<nfa.getColCount()<<endl;

	/* 2. init and parse DFAtable instance based on nfa */
	DFAtable dfa(nfa);
	vector<string> vec_T = e_closure_s("0", nfa, dfa);
	cout<<endl<<endl<<" e-closure(s0) :  "<<endl;
	printVec(vec_T);
	
	while(dfa.getUnTaggedCount() > 0)	// while DFAtable has an untagged state T
	{
		string T = dfa.completeTag();
		cout<<"\n\nthis turn's State : "<<T<<endl;
		cout<<"current state's nodes :  ";
		printVec(dfa.getNodesInState(T));

		for(int i=0; i<nfa.getColCount()-1; i++)	// traverse : every input char in NFAtable
		{
			char a = nfa.getColMeta()[i];
			vector<string> vec = move(T, a, nfa, dfa);
			cout<<"move("<<T<<", "<<a<<") :  ";
			printVec(vec);
			vector<string> U = e_closure_T(vec , nfa, dfa);
			cout<<" U : ";
			printVec(U);

			int U_idx = dfa.isExistInDFA(U);
			if( U_idx == -1 )
			{
				U_idx = dfa.addUnTaggedState(U);
			}
			dfa.addDtranEntry(T, a, U_idx);
			//dfa.show();
		}
	}
	/* 3. show result: DFAtable's Dtran */
	cout<<endl<<endl<<"*** DFAtable Dtran ***"<<endl;
	dfa.show();

	return 0;
}