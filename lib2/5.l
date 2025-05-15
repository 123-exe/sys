%%
[ \t\n]+;
-?([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)+	 {printf("%s: is a floating number.\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]*	 { printf("%s: is an identifier\n", yytext); }
.	{printf("%s: is a symbol\n",yytext);}
%%

int main(){
	yylex();
}
