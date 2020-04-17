/*
	ex3 - lex
	1427405017
	Jiayun Shen
*/
/* scanner for a prog.txt demo */

%{
/* need this for the call to atof() below */
#include <math.h>
%}

DIGIT    [0-9]
ID	    [a-z][a-z0-9]*

%%

{DIGIT}+    {
	   printf( "< integer: %s (%d) >\n", yytext, atoi( yytext ) );
	}

{DIGIT}+"."{DIGIT}*	      {
	   printf( "< float: %s (%g) >\n", yytext, atof( yytext ) );
	}

if|else|while|for|int|void|char|float|double	{
		printf( "< keyword: %s >\n", yytext );
	}

{ID}	       {
		printf( "< identifier: %s >\n", yytext );
	}

"+"|"-"|"*"|"/"|"&"|"->"|"."|"="	{
		printf( "< operator: %s >\n", yytext );
	}
	
"<<"|">>"	{
		printf( "< stream: %s >\n", yytext );
	}
	
"<="|"<"|"=="|">="|">"	{
		printf( "< compare: %s >\n", yytext );
	}

"("|")"|"{"|"}"	{
		printf( "< brackets: %s >\n", yytext );
	}

"\"".*"\""	{
		printf( "< string: %s >\n", yytext );
	}
	
[ \t\n]+	     /* eat up whitespace */

";"		/* eat up assistant character ; and " */

"//".*"\n"|"/*".*"*/"	/* eat up comments */

.	       {
		printf( "Unrecognized character: %s\n", yytext );
	}

%%

int yywrap() {
return 1;
}