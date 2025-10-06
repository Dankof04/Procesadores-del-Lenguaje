%{
//Declaración de variables, incluyendo las numéricas y las que albergarán texto, inicializando las mismas a 0 y a NULL respectivamente
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


 //Creamos los diferentes estados por los que viajaremos a lo largo del programa. COM es inclusivo porque podemos encontrarnos un comentario en cualquier parte del programa
%s COM
%x ARGS VARS BODY SELECT UPDATE DELETE


 //Con option indicamos la utilización de la pila y de la opción Caseless, para trabajar con mayúsculas y minúsculas de forma más sencilla

%option stack caseless


texto_generico [A-Z0-9\_]+
espacio_tabulacion [ \t]*


%%

%{
//Con <*> indicamos que estas expresiones regulares se pueden encontrar en cualquier parte del programa, en cualquier estado
%}

<*>--.*\n                                                               {/* Ignorar comentario de una línea */}
<*>[ \t]*"/*"                                                           { yy_push_state(COM); /* Introducimos en la pila el estado actual y viajamos a COM */}


<COM>[^*/]*"\n"*                                                        {}
<COM>[ \t]*"*/""\n"*                                                    { yy_pop_state(); /* Sacamos de la pila el ultimo estado almacenado y viajamos al mismo */}

%{
//Estas siguientes tres expresiones regulares no sirven para nada, más allá de la mera practica. A efectos de análisis, no harán nada más que detectar un CREATE, un OR o un REPLACE, sin ninguna acción.
%}
CREATE[ \t]+
OR[ \t]+
REPLACE[ \t]+

%{
//Si detectamos un PROCEDURE seguido de su nombre y un parentesis abierto, pasamos al estado ARGS para contar los argumentos
%}

PROCEDURE{espacio_tabulacion}{texto_generico}[\n]*\([\n]*               { BEGIN(ARGS); }

%{
//Aquí tenemos dos tipos de argumentos, los intermedios (seguidos de coma) y los finales (seguidos de un cierre de paréntesis). El punto a través del cual pasaremos al siguiente estado será IS o AS
%}

<ARGS>{espacio_tabulacion}{texto_generico},[\n]*                        { contador_argumentos++; }
<ARGS>{espacio_tabulacion}{texto_generico}[\n]*\)[\n]*                  { contador_argumentos++; }
<ARGS>IS{espacio_tabulacion}                                            { BEGIN(VARS); }
<ARGS>AS{espacio_tabulacion}                                            { BEGIN(VARS); }

%{
//Simplemente contamos las variables, que podrán estar seguidas de un salto de línea. Cuando detectemos el BEGIN, pasaremos a lo que sería el cuerpo del procedimiento
%}

<VARS>{espacio_tabulacion}{texto_generico};[\n]*                        { contador_variables++; }
<VARS>BEGIN[\n]*                                                        { BEGIN(BODY); }


%{
//Aquí tenemos las diferentes condiciones para viajar a cada estado, si detectamos SELECt con texto en medio y un FROM, viajamos a SELECT, y si detectamos un UPDATE o un DELETE, usamos un lookahead para no introducirlo en yytext y poder volver a leerlo después
%}

<BODY>SELECT([^;])*FROM                                                 { BEGIN(SELECT);}
<BODY>[ \t]/UPDATE                                                      { BEGIN(UPDATE); }
<BODY>[ \t]/DELETE                                                      { BEGIN(DELETE); }

%{
//Si detectamos un END seguido de texto y ;, volvemos a INITIAL tal y como se muestra en el diagrama de estados proporcionado
%}
<BODY>END[^;]+;                                                         { BEGIN(INITIAL); }


%{
//En estos dos casos simplemente establecemos la longitud si fuera mayor a la que tenemos registrada previamente y volvemos a BODY por si hubiera más operaciones UPDATE o DELETE
%}
<UPDATE>UPDATE[^;]+;                                                    {   long_up_del=yyleng; 
                                                                            if(long_up_del>max_long_up_del){ 
                                                                                max_long_text=strdup(yytext); 
                                                                                max_long_up_del=long_up_del; 
                                                                            }
                                                                            long_up_del=0;
                                                                            BEGIN(BODY);
                                                                        } 

<DELETE>DELETE[^;]+;                                                    {   long_up_del=yyleng; 
                                                                            if(long_up_del>max_long_up_del){ 
                                                                                max_long_text=strdup(yytext); 
                                                                                max_long_up_del=long_up_del; 
                                                                            }
                                                                            long_up_del=0;
                                                                            BEGIN(BODY);
                                                                        }                                      

%{
//Aquí manejamos las tablas del SELECT, en la que tenemos dos opciones: tabla intermedia y tabla final. La tabla intermedia es texto seguido por una coma, mientras que la final acaba en WHERE o en ;
//Recogemos el texto para cada expresion regular con yymore, para luego copiarlo en una variable adicional con strdup y asi almacenar el mayor numero de tablas
//Usamos el lookahead / para exigir ciertos caracteres en la expresión regular pero no incluirlos en yytext, para procesarlos despues y poder salir facilmente del estado SELECT
%}


<SELECT>{espacio_tabulacion}{texto_generico},                           { contador_tablas++; yymore(); }
<SELECT>{espacio_tabulacion}{texto_generico}{espacio_tabulacion}/;      { contador_tablas++; yymore(); tablas_text=strdup(yytext); }
<SELECT>{espacio_tabulacion}{texto_generico}" "/WHERE                   { contador_tablas++; yymore(); tablas_text=strdup(yytext); }


<SELECT>WHERE                                                           { if(contador_tablas>max_tablas){max_tablas=contador_tablas; max_tablas_text=strdup(tablas_text); }; contador_tablas=0; BEGIN(BODY); }
<SELECT>;                                                               { if(contador_tablas>max_tablas){max_tablas=contador_tablas; max_tablas_text=strdup(tablas_text); }; contador_tablas=0; BEGIN(BODY); }


.|\n                                                                    {} 
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

    printf("- Número de argumentos: %d\n", contador_argumentos);
    printf("- Número de variables locales: %d\n", contador_variables);
    printf("- La operación UPDATE o DELETE con mayor número de caracteres es: \n\"%s\"\n", max_long_text);
    printf("- La consulta SELECT con más tablas tiene %d y son: %s\n", max_tablas,max_tablas_text);

    return 0;
}