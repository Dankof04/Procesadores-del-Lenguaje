%{
/*
 * Autor: Daniel Miguel Muiña
 * Correo electrónico: dmm1017@alu.ubu.es
 * Versión: 1.0
 * Descripción: Programa en Bison con el que implementamos un parser para un lenguaje sencillo que incluye sentencias de asignación, selección, iteración e impresión.
 * Asignatura: Procesadores del Lenguaje
 * Curso: 2025/2026
 * Profesor: Alvar Arnáiz González
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos una variable global para llevar un registro de las etiquetas generadas
int label_actual = 0;

// Función para generar la siguiente etiqueta
// Simplemente devuelve la cadena "LBL" seguida del numero actual para la etiqueta y luego incrementa el contador
char* new_label() {
    char* buffer = (char*)malloc(20);
    sprintf(buffer, "LBL%d", label_actual++); //Hacemos uso de la función sprintf para escribir LBLX en buffer y poder devolverlo de forma sencilla
    return buffer;
}

int yylex();
void yyerror(char *s);

%}

%union {
    char *str;
}




// Definición de los tokenes que contienen identificadores y números (axiomas) y tipos para etiquetas
%token <str> NUM ID
%type <str> sel_stmt_condition
%type <str> iter_stmt_while iter_stmt_condition iter_stmt_hacer

// Definición de tokenes de palabras reservadas
%token IMPRIMIR SI SINO MIENTRAS HACER


// Definición de tokenes de símbolos usados en la gramática
%token PUNTO_COMA PAREN_IZQ PAREN_DER LLAVE_IZQ LLAVE_DER
%token IGUAL MAS_IGUAL MENOS_IGUAL MULT_IGUAL DIV_IGUAL
%token SUMA RESTA MULT DIV


%%


//Producción inicial que representa una lista de sentencias
list_sntncs: 
    sntnc PUNTO_COMA | 


    list_sntncs sntnc PUNTO_COMA // Detecta sentencias seguidas de punto y coma recursivamente
    ;



//Producción que representa una sentencia de cualquier tipo dentro de las contempladas en la gramática
sntnc: 
    sel_stmt |


    iter_stmt |


    assig_stmt |


    print_stmt |
    ;



//Producción que representa una sentencia de impresión
print_stmt:
    IMPRIMIR PAREN_IZQ expr PAREN_DER
        {
            printf("\tprint\n"); // Imprime "print" al final de la sentencia
        }
    ;



// Auxiliar para selección: evalúa la condición
sel_stmt_condition:
    SI PAREN_IZQ expr PAREN_DER
        {
            $$ = new_label();
            printf("\tsifalsovea %s\n", $$); // Despues de evaluar la expresión, si es falsa salta a la etiqueta generada
        }
    ;



//Producción que representa una sentencia de selección (if-else)
sel_stmt:
    sel_stmt_condition LLAVE_IZQ list_sntncs LLAVE_DER
        {
            printf("%s\n", $1); // Imprime la etiqueta de salida (que era la del salto condicional)
            free($1);
        }|


    sel_stmt_condition LLAVE_IZQ list_sntncs LLAVE_DER SINO
        {
            char *lbl_salida = new_label(); //Para no ejecutar el else si la condición fuera verdadera
            printf("\tvea %s\n", lbl_salida); // Al final del if, salta a lbl_salida para evitar ejecutar el else
            printf("%s\n", $1); // Imprime la etiqueta anterior para comenzar el bloque else
            free($1);
            $1 = lbl_salida; // Guardamos la nueva etiqueta de salida para usarla al final
        }
    LLAVE_IZQ list_sntncs LLAVE_DER
        {
            printf("%s\n", $1); // Por ultimo imprimimos la etiqueta de salida
            free($1);
        }
    ;



// Auxiliar iteración: MIENTRAS
iter_stmt_while: 
    MIENTRAS
        {
            $$ = new_label();
            printf("%s\n", $$); // Mostramos la etiqueta del bucle antes de evaluar la expresión
        }
    ;



// Auxiliar iteración: Condición del MIENTRAS
iter_stmt_condition: 
    PAREN_IZQ expr PAREN_DER
        {
            $$ = new_label();
            printf("\tsifalsovea %s\n", $$); // Una vez evaluada la expresión, viajaremos a la etiqueta de salida si fuera falsa
        }
    ;



// Auxiliar iteración: HACER
iter_stmt_hacer: 
    HACER
        {
            $$ = new_label();
            printf("%s\n", $$); // Creamos la etiqueta del bucle (solo habrá una porque evaluamos al final)
        }
    ;



//Producción que representa una sentencia de iteración (while o do-while)
iter_stmt: 
    iter_stmt_while iter_stmt_condition LLAVE_IZQ list_sntncs LLAVE_DER
        {
            printf("\tvea %s\n", $1); // Volvemos a la etiqueta del bucle para reevaluar la expresión
            printf("%s\n", $2); // Imprimimos la etiqueta de salida para cuando la condición del bucle sea falsa
            free($1);
            free($2);
        }|


    iter_stmt_hacer LLAVE_IZQ list_sntncs LLAVE_DER MIENTRAS PAREN_IZQ expr PAREN_DER
        {
            printf("\tsiciertovea %s\n", $1); // Evaluamos la expresión y si fuera cierta, volveriamos a la etiqueta del principio
            free($1);
        }
    ;



//Producción que representa una sentencia de asignación
assig_stmt:
    ID
        { printf("\tvalori %s\n", $1); } // Imprimimos el valori del ID
    IGUAL expr
        {
            printf("\tasigna\n");
            free($1);
        }|

    //Para cada tipo de asignación compuesta, imprimimos la secuencia de operaciones correspondiente
    ID
        { printf("\tvalori %s\n", $1); }
    MAS_IGUAL
        { printf("\tvalord %s\n", $1); }
    expr
        {
            printf("\tsum\n");
            printf("\tasigna\n");
            free($1);
        }|


    ID
        { printf("\tvalori %s\n", $1); }
    MENOS_IGUAL
        { printf("\tvalord %s\n", $1); }
    expr
        {
            printf("\tsub\n");
            printf("\tasigna\n");
            free($1);
        }|


    ID
        { printf("\tvalori %s\n", $1); }
    MULT_IGUAL
        { printf("\tvalord %s\n", $1); }
    expr
        {
            printf("\tmul\n");
            printf("\tasigna\n");
            free($1);
        }|


    ID
        { printf("\tvalori %s\n", $1); }
    DIV_IGUAL
        { printf("\tvalord %s\n", $1); }
    expr
        {
            printf("\tdiv\n");
            printf("\tasigna\n");
            free($1);
        }
    ;



//Producción que representa una expresión aritmética de suma o resta
expr:
    expr SUMA mult_expr
        {
            printf("\tsum\n"); // Al encontrar una suma, imprimimos dicha operación
        }|


    expr RESTA mult_expr
        {
            printf("\tsub\n"); // Lo mismo con la resta
        }|


    mult_expr
    ;



//Producción que representa una expresión aritmética de multiplicación o división
mult_expr:
    mult_expr MULT val
        {
            printf("\tmul\n"); // Al encontrar una multiplicación, imprimimos dicha operación
        }|


    mult_expr DIV val
        {
            printf("\tdiv\n"); // Lo mismo con la división
        }|


    val
    ;



//Produccion que representa un valor, sea número, identificador o expresión entre paréntesis
val:    
    NUM
        {
            printf("\tmete %s\n", $1); // Imprimimos el mete con el valor del número
            free($1);
        }|


    ID
        {
            printf("\tvalord %s\n", $1); // Imprimimos el valord con el valor del identificador
            free($1);
        }| 


    PAREN_IZQ expr PAREN_DER
   ;



%%


//Creamos el main para ejecutar el parser
int main(int argc, char** argv) {
    //Verificamos si se ha pasado un argumento al ejecutar el programa
    if (argc > 1) {
        extern FILE *yyin;
        //Si se ha pasado un argumento, se utilizará el fichero del mismo como entrada
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error al abrir el fichero");
            return 1;
        }
    }
    
    //Ejecuta el parser comenzando por el axioma
    yyparse();
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

int yywrap() {
    return 1;
}