
 int contador=0;

%%

[ \t\n]*\n		contador++;


.|\n			;

%%

int main(){
	yylex();
	printf("El número de líneas vacías es: %d\n",contador);
	return 0;
}
