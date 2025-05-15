%%
[ \t\n]+;
am|is|are|was|were|be|being|been|do|does|did|will|would|should|can|could|has|have|had|go  { 
    printf("%s is a verb\n", yytext); 
}
[a-zA-Z]+ { printf("%s is not a verb\n", yytext); } 
. {}
%%

int main(void) {
    yylex();
    return 0;
}
