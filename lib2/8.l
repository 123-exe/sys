%%
[ \t\n]+         ;  // Ignore whitespace
[0-9] {printf("%s: is a digit\n", yytext);}
[0-9]+ {printf("%s: is not a digit\n", yytext);}
[a-zA-Z]+ {printf("%s is not a digit\n",yytext);}
.                ;  // Ignore everything else
%%

int main(void) {
    yylex();
    return 0;
}
