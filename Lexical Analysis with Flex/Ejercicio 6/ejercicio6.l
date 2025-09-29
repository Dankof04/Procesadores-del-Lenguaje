


%%


^[A-Za-z]+/" "		printf("\nInicia linea: %s",yytext);


[A-Za-z]+$		printf("\nFinaliza linea: %s\n",yytext);

.|\n			;


%%

int main(){
	yylex();
	return 0;
}
