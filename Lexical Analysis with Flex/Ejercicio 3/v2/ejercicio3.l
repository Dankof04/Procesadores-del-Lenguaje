
 int contador_espacios=0;
 int contador_tabulaciones=0;

%%

[^\n]+\n	{ for(int i=0; yytext[i]!='\n';i++){
			if(yytext[i]==' '){
				contador_espacios++;
			}else if(yytext[i]=='\t'){
				contador_tabulaciones++;
		  	}
		  }
		}

.|\n		;

%%

int main(){
	yylex();
	printf("Número de espacios: %d\n",contador_espacios);
	printf("Número de tabulaciones: %d\n",contador_tabulaciones);
	return 0;
}

