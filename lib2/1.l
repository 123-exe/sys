%%
auto|break|case|char|const|\
continue|default|do|double|\
else|enum|extern|float|for|\
goto|if|inline|int|long|register|\
restrict|return|short|signed|sizeof|\
static|struct|switch|typedef|union|unsigned|\
void|volatile|while	{
	printf("%s: is a keyword\n",yytext);
}
[a-zA-Z_][a-zA-Z0-9_]*	{printf("%s: is not a keyword\n",yytext);}
[ \t\n]+	{}
.	{printf("%s: is a symbol\n",yytext);}
%%

int main(){
	yylex();
}
