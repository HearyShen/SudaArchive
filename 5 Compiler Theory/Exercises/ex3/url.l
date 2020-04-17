/*
	ex3 - lex
	1427405017
	Jiayun Shen
*/
/* scanner for a url and e-mail address demo */

%{
/* need this for the call to atof() below */
#include <math.h>
%}

DIGIT    [0-9]
URLCHAR	([a-zA-Z0-9]|"="|"-"|"_"|"?"|"%"|"&")	
MAILCHAR	([a-zA-Z0-9]|"_")

%%

(("http""s"{0,1})"://"){0,1}{URLCHAR}*("."{URLCHAR}*)+("/"{URLCHAR}+)*("."{URLCHAR}*){0,1}"/"{0,1}	{
		printf("< url: %s >\n", yytext);
	}
	
{MAILCHAR}+"@"{MAILCHAR}+("."{MAILCHAR}+)+	{
		printf("< e-mail: %s >\n", yytext);
	}


.	       {
		printf( "Unrecognized character: %s\n", yytext );
	}

%%

int yywrap() {
return 1;
}