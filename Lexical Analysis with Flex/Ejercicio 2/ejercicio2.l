
 int contador=0;

%%

[ \t]*\n		contador++;
[^ \t]+\n		;


.|\n			;

%%

int main(){
	yylex();
	printf("El número de líneas vacías es: %d\n",contador);
	return 0;
}
