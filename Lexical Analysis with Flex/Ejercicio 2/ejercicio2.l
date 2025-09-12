
 int contador=0;

%%

[^\n]+		;
\n		contador++;


%%

int main(){
	yylex();
	printf("El número de líneas vacías es: %d\n",contador);
	return 0;
}
