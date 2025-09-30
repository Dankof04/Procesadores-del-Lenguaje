%{
//Declaración de variables
int contador_argumentos=0;
int contador_variables=0;
%}

%s COM
%x PROCEDIMIENTO 
%x PARAMETROS

%option stack


%%

<*>--.*\n                                             {/* Ignorar comentario de una línea */}
<*>[ \t]*"/*"                                                { yy_push_state(COM); }


<COM>[^*/]*[\n]*                                    {}
<COM>[ \t]*"*/"                                          { yy_pop_state(); }

CREATE[ \t]+
OR[ \t]+
REPLACE[ \t]+
PROCEDURE[ \t]+[A-Za-z0-9\_]+[\n]*\([\n]*                { yy_push_state(PROCEDIMIENTO); }

<PROCEDIMIENTO>[ \t]*[A-Za-z0-9\_ ]+,[\n]*          { contador_argumentos++; }
<PROCEDIMIENTO>[ \t]*[A-Za-z0-9\_ ]+[\n]*           { contador_argumentos++; }
<PROCEDIMIENTO>[ \t]*[A-Za-z0-9\_ ]+/\)[\n]*        { contador_argumentos++; }
<PROCEDIMIENTO>\)                                   { yy_pop_state(); }




[ \t]*                                               {}
.|\n                                                { /* Ignorar cualquier otro carácter */ } 
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
    return 0;
}