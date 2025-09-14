
 int desplazamiento;

%%

[a-zA-Z0-9]		printf("%c",yytext[0]+desplazamiento);



%%

int main(){
	printf("Introduce el número correspondiente al desplazamiento del cifrado César: ");
	scanf("%d", &desplazamiento);

	yylex();
	
	return 0;

}
