%%
[ \t]+                                      ;  // Ignore whitespace

-([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)            { printf("%s: is a negative float\n", yytext); }

\+?([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)          { printf("%s: is a positive float\n", yytext); }

-[0-9]+                                     { printf("%s: is a negative integer\n", yytext); }

\+?[0-9]+                                   { printf("%s: is a positive integer\n", yytext); }

\n                                          { putchar('\n'); }
.                                           ;  // Ignore everything else
%%

int main(void) {
    yylex();
    return 0;
}
