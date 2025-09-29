 //Declaración de variables
 int contador_argumentos=0;
 int contador_variables=0;


 //Declaración de condiciones de arranque
 %s COMENTARIO


%%

<COMENTARIO>


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
    return 0;
}



