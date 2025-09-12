
 int contador=0;

%%

[^\n]+\n	{ for(int i=0; yytext[i]!='\n';i++){
			if(yytext[i]==' ' || yytext[i]=='\t'){
				contador++;
			}
		  }
		}

.|\n		;

%%

int main(){
	yylex();
	printf("Número de espacios/tabulaciones: %d\n",contador);
	return 0;
}

