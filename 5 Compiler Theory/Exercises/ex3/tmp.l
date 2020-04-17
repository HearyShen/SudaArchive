%{
#include "stdio.h"
%}

%%
(a|b)*ab                     printf("Pattern (a|b)*ab matched: %s\n",yytext);
(00|11|(01|10)(00|11)*(01|10))*  printf("Pattern: even_num_0_1: %s\n", yytext);
z{2,4}[^z\n]*                       printf("Pattern fix freq matched: %s\n", yytext);
(.*)                         printf("Pattern not matched: %s\n", yytext);
%%

int yywrap() {
return 1;
}
