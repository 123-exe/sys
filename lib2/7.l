%%
[ \t\n]+         ;  // Ignore whitespace

";"|","|"\\."|":"|"'"|":-"|"-"|"\?"|"!"  { printf("%s: is a punctuation symbol\n", yytext); }
[a-zA-Z]+ {printf("%s is not a punctuation symbol\n",yytext);}
.                ;  // Ignore everything else
%%

int main(void) {
    yylex();
    return 0;
}
