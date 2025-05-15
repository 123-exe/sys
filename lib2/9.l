%%
[ \t\n]+         ;  // Ignore whitespace

"=="|"!="|"<"|"="|">"|"<=|"">="   { printf("%s: is a relational operator\n", yytext); }
"&&"|"||"|"!"    { printf("%s: is a logical operator\n", yytext); }
"%"|"+"|"-"|"*"|"/"  { printf("%s: is an arithmetic operator\n", yytext); }
"="|"+="|"-="|"*="|"/="|"%=" { printf("%s: is an assignment operator\n", yytext); }
"++"|"--"         { printf("%s: is a unary operator\n", yytext); }

[a-zA-Z]+         { printf("%s: is not an operator\n", yytext); }  // Match identifiers (variables)

.                 { printf("%s: is not an operator\n", yytext); }  // Catch everything else
%%

int main(void) {
    yylex();
    return 0;
}
