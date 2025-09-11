/*
Hacer un programa que cuente el número de líneas con menos de:
	a) 30 caracteres
	b) 30 letras
*/


 int contador=0;


%%

[^\n]*		{if(yyleng<30){contador++;}}

.|\n		;

%%

int main(){
	yylex();
	printf("Número de lineas con menos de 30 caracteres: %d\n", contador);	
	return 0;
}
