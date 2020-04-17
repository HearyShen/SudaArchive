/* 
ex1_1
中缀表达式转后缀表达式
	1、语法制导的定义
1427405017
沈家赟

input example: 
( expr  ( expr ( expr ( term ( 9 ) ) ) ( - ) ( term (5 ) ) )  ( + )  ( term ( 2 ) ) ) 
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_LENGTH 100
#define T_LENGTH 20

struct Node{
	char t[T_LENGTH];
	bool isExpr;
	Node *parent;
	Node *left;
	Node *right;
	char data;
};

Node* parseTree(char *str);
void traverse(Node* root);
void getCurrentT(Node* root);
void visitTree(Node* root);
void deleteTree(Node* root);
char* str_removeSpace(char* str);

char t_current[T_LENGTH];

void main()
{
	char str_in[MAX_LENGTH];
	char t;
	Node* root;

	while(true)
	{
		printf("ex1_1 postfix\n中缀表达式转后缀表达式 - 语法制导的定义\n");
	
		puts("Please type in (end with Enter):");
		gets(str_in);

		/* preprocess the input str */
		strlwr(str_in);				// convert str to lower case
		str_removeSpace(str_in);	// remove redundant space in str

		/* parse the input str to corresponding tree */
		root = parseTree(str_in);
		if(root == NULL)
		{
			puts("error occured during parsing tree, invalid input format!\n\n");
			continue;
		}

		/* traverse and fill in all expr.t and term.t */
		traverse(root);

		/* get postfix */
		puts("the postfix format:");
		puts(root->t);

		/* traverse the tree to free allocated memory */
		puts("\n\nNow free heap memory for tree...");
		deleteTree(root);

		puts("\nPress Enter to continue\n");
		gets(&t);
	}
}


Node* parseTree(char *str)
{
	int depth=0, idx=0;
	char detect[5];
	Node* root = NULL;
	Node* current = root;
	bool isRoot = true;

	if(str==NULL || strlen(str)==0)
	{
		return NULL;
	}

	while(true)
	{
		if(str[idx] == '(')
		{
			idx++;	// index to next item
			strncpy(detect,&str[idx],4);
			detect[4] = 0;
			

			if(strcmp(detect, "expr") == 0)	// match "expr" (0 for equal)
			{
				idx += 4;	// index to next item

				Node* node = (Node*)malloc(sizeof(Node));
				node->isExpr = true;
				node->parent = current;
				node->left = NULL;
				node->right = NULL;
				node->data = 0;
				
				if(isRoot == true)
				{
					root = node;
					isRoot = false;
				}
				else
				{
					if( current->isExpr == true && current->left == NULL)
					{
						current->left = node;
					}
					else if( current->isExpr == true && current->right == NULL)
					{
						current->right = node;
					}
					else
					{
						return NULL;
					}
				}
				current = node;	// update current ptr
				depth++;

				continue;
			}


			if(strcmp(detect, "term") == 0)	// match "term" (0 for equal)
			{
				idx += 4;	// index to next item
				if(str[idx] == '(')
				{
					idx++;	// index to next item

					if(str[idx]>='0' && str[idx]<='9')	// match digit after term
					{
						Node* node = (Node*)malloc(sizeof(Node));
						node->isExpr = false;
						node->parent = current;
						node->left = NULL;
						node->right = NULL;
						node->data = str[idx];

						if(current->isExpr == true && current->left == NULL && current->data == 0)
						{
							current->left = node;
						}
						else if(current->isExpr == true && current->left != NULL && current->data != 0)
						{
							current->right = node;
						}
						else
						{
							return NULL;
						}
						idx += 2;	// skip corresponding bracket
						idx++;		// index to next item
					}
					else
					{
						return NULL;
					}
				}
				else
				{
					return NULL;
				}
				continue;
			}


			if(str[idx] == '+' || str[idx] == '-' || str[idx] == '*' || str[idx] == '/')	// match operator
			{
				current->data = str[idx];
				idx += 1;	// skip corresponding bracket
				idx++;
				continue;
			}
			
		}

		if(str[idx] == ')')
		{
			current = current->parent;
			depth--;
			idx++;
			continue;
		}
		break;
	}

	return root;
}

void getCurrentT(Node* root)
{
	char tmp[2] = {0};
	if(root == NULL)
	{
		return;
	}
	
	getCurrentT(root->left);
	getCurrentT(root->right);
	if(root->data != 0)
	{
		tmp[0] = root->data;
		strcat(t_current, tmp);		// using global variable t_current[]
		return;
	}
	return;
}

void traverse(Node* root)
{
	char tmp[T_LENGTH] = {0};
	if(root == NULL)
	{
		return;
	}
	
	traverse(root->left);
	traverse(root->right);

	strcpy(t_current, tmp);	// clear
	getCurrentT(root);		// traverse and get t
	strcpy(root->t, t_current);
}

void visitTree(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	visitTree(root->left);
	visitTree(root->right);
	if(root->data != 0)
	{
		printf("%c",root->data);
		return;
	}
}

void deleteTree(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	deleteTree(root->left);
	deleteTree(root->right);
	if(root->data != 0)
	{
		printf("delete %c\n",root->data);
	}
	free(root);
}

char* str_removeSpace(char* str)
{
	int i=0, j=0, templength=0;
	
	while(true)
	{
		if(str[i] == NULL)
		{
			return NULL;
		}
		if(str[i] == ' ')	// remove the space in str[i]
		{
			templength = strlen(str);
			for(j=i; j<templength; j++)
			{
				str[j] = str[j+1];
			}
			i--;	// back step
		}
		i++;	// iterator
	}
	return str;
}