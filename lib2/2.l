%%
[a-zA-Z_][a-zA-Z0-9_]*	{printf("%s: is a identifier.\n",yytext);}
[0-9][a-zA-Z0-9]* {printf("%s: is not a identifier.\n",yytext);}
[ \t\n]+	{}
.	{printf("%s: is a symbol\n",yytext);}
%%

int main(){
	yylex();
}
