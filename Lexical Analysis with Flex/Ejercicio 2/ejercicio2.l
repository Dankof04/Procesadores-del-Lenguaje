
 int contador=0;

%%

[^\n]*\n	{
		for(int i=0;yytext[i]!='\n';i++){
			if(yytext[i]!=' ' && yytext[i]!='\t'){
				return 1;
			}
		}
		contador++;
		}
.|\n			;

%%

int main(){
	yylex();
	printf("El número de líneas vacías es: %d\n",contador);
	return 0;
}
