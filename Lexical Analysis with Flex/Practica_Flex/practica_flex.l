%{
//Declaración de variables
int contador_argumentos=0;
int contador_variables=0;
%}

%s COMENTARIO
%x PROCEDIMIENTO 
%x PARAMETROS

%option stack


%%

--                  { yy_push_state(COMENTARIO); }
CREATE[ \t]+              { yy_push_state(PROCEDIMIENTO); }



<COMENTARIO>.*\n    { printf("Comentario detectado\n"); yy_pop_state(); }


<PROCEDIMIENTO>OR[ \t]+|REPLACE[ \t]+|PROCEDURE[ \t]+[A-Za-z0-9]+\(   {}

<PROCEDIMIENTO>[A-Za-z0-9 ]+,    { contador_argumentos++; }
<PROCEDIMIENTO>[A-Za-z0-9 ]+/\)    { contador_argumentos++; }
<PROCEDIMIENTO>\)                       { yy_pop_state(); }

[ \t\n]+            { /* Ignorar espacios en blanco */ }




.|\n                { /* Ignorar cualquier otro carácter */ } 
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