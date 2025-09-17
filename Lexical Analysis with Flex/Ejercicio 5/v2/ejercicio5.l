 #define OFFSET 5
 char letra_nueva;


%%

[A-Z]		{ letra_nueva=yytext[0] + OFFSET;
		if (letra_nueva > 'Z')
			letra_nueva = letra_nueva + 'A' -'Z';
		printf("%c",letra_nueva);
		}

[a-z]		{ letra_nueva=yytext[0] + OFFSET;
		if (letra_nueva > 'z')
			letra_nueva = letra_nueva + 'a' -'z';
		printf("%c",letra_nueva);
		}



%%
