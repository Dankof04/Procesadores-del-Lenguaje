%{
//Declaración de variables
int contador_argumentos=0;
int contador_variables=0;
int contador_tablas=0;
int max_tablas=0;
int long_up_del=0;
int max_long_up_del=0;
char *tablas_text=NULL;
char *max_tablas_text=NULL;
char *max_long_text=NULL;
%}

%s COM
%x ARGS VARS BODY SELECT UPDATE DELETE

%option stack caseless


texto_generico [A-Z0-9\_]+
espacio_tabulacion [ \t]*


%%

<*>--.*\n                                                       {/* Ignorar comentario de una línea */}
<*>[ \t]*"/*"                                                   { yy_push_state(COM); }


<COM>[^*/]*"\n"*                                                {}
<COM>[ \t]*"*/""\n"*                                            { yy_pop_state(); }


CREATE[ \t]+
OR[ \t]+
REPLACE[ \t]+
PROCEDURE{espacio_tabulacion}{texto_generico}[\n]*\([\n]*       { BEGIN(ARGS); }



<ARGS>{espacio_tabulacion}{texto_generico},[\n]*                { contador_argumentos++; }
<ARGS>{espacio_tabulacion}{texto_generico}[\n]*\)[\n]*          { contador_argumentos++; }
<ARGS>IS{espacio_tabulacion}                                    { BEGIN(VARS); }
<ARGS>AS{espacio_tabulacion}                                    { BEGIN(VARS); }


<VARS>{espacio_tabulacion}{texto_generico};[\n]*                { contador_variables++; }
<VARS>BEGIN[\n]*                                                { BEGIN(BODY); }

<BODY>SELECT([^;])*FROM                                   { yy_push_state(SELECT);}
<BODY>[ \t]/UPDATE                                          { yy_push_state(UPDATE); }
<BODY>[ \t]/DELETE                                                 { yy_push_state(DELETE); }
<BODY>END[^;]+;                                                 { BEGIN(INITIAL); }

<UPDATE>UPDATE[^;]+;                                           {   long_up_del=yyleng; 
                                                                    if(long_up_del>max_long_up_del){ 
                                                                        max_long_text=strdup(yytext); 
                                                                        max_long_up_del=long_up_del; 
                                                                    }
                                                                    long_up_del=0;
                                                                    yy_pop_state();
                                                                } 

<DELETE>DELETE[^;]+;                                           {   long_up_del=yyleng; 
                                                                    if(long_up_del>max_long_up_del){ 
                                                                        max_long_text=strdup(yytext); 
                                                                        max_long_up_del=long_up_del; 
                                                                    }
                                                                    long_up_del=0;
                                                                    yy_pop_state();
                                                                }                                      

<SELECT>{espacio_tabulacion}{texto_generico},                   { contador_tablas++; yymore(); }
<SELECT>{espacio_tabulacion}{texto_generico}{espacio_tabulacion}/;                  { contador_tablas++; yymore(); tablas_text=strdup(yytext); }
<SELECT>{espacio_tabulacion}{texto_generico}" "/WHERE                                  { contador_tablas++; yymore(); tablas_text=strdup(yytext); }
<SELECT>WHERE                                               { if(contador_tablas>max_tablas){max_tablas=contador_tablas; max_tablas_text=strdup(tablas_text); }; contador_tablas=0; yy_pop_state(); }
<SELECT>;                                               { if(contador_tablas>max_tablas){max_tablas=contador_tablas; max_tablas_text=strdup(tablas_text); }; contador_tablas=0; yy_pop_state(); }


.|\n                                                            {} 
%%

int main(int argc, char **argv){
    if(argc > 1) {
        FILE *file;
        file = fopen(argv[1], "r");
        if(!file) {
            printf("No se puede abrir el fichero %s\n", argv[1]);
            exit(1);
        }
        yyin = file;
    } 
    else {
        yyin = stdin; // Esto no es necesario, pues es el comportamiento de flex por defecto
    }

    yylex();

    printf("Número de argumentos: %d\n", contador_argumentos);
    printf("Número de variables locales: %d\n", contador_variables);
    printf("La consulta SELECT con más tablas tiene %d\n y son: %s\n", max_tablas,max_tablas_text);
    printf("La operación UPDATE o DELETE con mayor número de caracteres es: %s\n", max_long_text);

    free(tablas_text);
    free(max_tablas_text);
    return 0;
}