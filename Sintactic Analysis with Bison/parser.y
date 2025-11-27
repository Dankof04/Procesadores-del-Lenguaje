%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaramos las funciones externas */
int yylex();
void yyerror(char *s);
%}

%union {
    char *str;
}

%token <str> NUM ID
%token IMPRIMIR SI SINO MIENTRAS HACER
%token PUNTO_COMA PAREN_IZQ PAREN_DER LLAVE_IZQ LLAVE_DER
%token IGUAL MAS_IGUAL MENOS_IGUAL MULT_IGUAL DIV_IGUAL
%token SUMA RESTA MULT DIV


%%


list_sntncs: list_sntncs sntnc PUNTO_COMA
           | 
           ;

sntnc: sel_stmt
     | iter_stmt
     | assig_stmt
     | print_stmt
     ;


print_stmt: IMPRIMIR PAREN_IZQ expr PAREN_DER
          ;


assig_stmt: ID IGUAL expr
          | ID MAS_IGUAL expr
          | ID MENOS_IGUAL expr
          | ID MULT_IGUAL expr
          | ID DIV_IGUAL expr
          ;


m_si: SI PAREN_IZQ expr PAREN_DER 
    ;

sel_stmt: m_si LLAVE_IZQ list_sntncs LLAVE_DER
        | m_si LLAVE_IZQ list_sntncs LLAVE_DER SINO LLAVE_IZQ list_sntncs LLAVE_DER
        ;


stmt_while_begin: MIENTRAS
                ;

stmt_while_cond: stmt_while_begin PAREN_IZQ expr PAREN_DER
               ;

m_hacer: HACER
       ;

iter_stmt: stmt_while_cond LLAVE_IZQ list_sntncs LLAVE_DER
         | m_hacer LLAVE_IZQ list_sntncs LLAVE_DER MIENTRAS PAREN_IZQ expr PAREN_DER
         ;

expr: expr SUMA mult_expr
    | expr RESTA mult_expr
    | mult_expr
    ;

mult_expr: mult_expr MULT val
         | mult_expr DIV val
         | val
         ;

val: NUM
   | ID
   | PAREN_IZQ expr PAREN_DER
   ;



%%


int main(int argc, char** argv) {
    if (argc > 1) {
        extern FILE *yyin;
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error al abrir el fichero");
            return 1;
        }
    }
    
    yyparse();
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

int yywrap() {
    return 1;
}