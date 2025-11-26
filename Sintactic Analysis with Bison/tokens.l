%{

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h" //Para enlazarlo con el parser de Bison

%}

%option noyywrap

%%

 //Ignoramos espacios, tabulaciones, saltos de linea y comentarios (de una linea y multilinea)
 [ \t\n]+           ;
 "//".*             ;
 "/*"([^*]|"*"+[^*/])*"*"+"/"  ;

 //Tokens para la gramática
 ";"                        { return PUNTO_COMA; }
 "("                        { return PAREN_IZQ; }
 ")"                        { return PAREN_DER; }
 "{"                        { return LLAVE_IZQ; }
 "}"                        { return LLAVE_DER; }
 "="                        { return IGUAL; }
 "+="                       { return MAS_IGUAL; }
 "-="                       { return MENOS_IGUAL; }
 "*="                       { return MULT_IGUAL; }
 "/="                       { return DIV_IGUAL; }
 "+"                        { return SUMA; }
 "-"                        { return RESTA; }
 "*"                        { return MULT; }
 "/"                        { return DIV; }


 "imprimir"                 { return IMPRIMIR; }
 "si"                       { return SI; }
 "sino"                     { return SINO; }
 "mientras"                 { return MIENTRAS; }
 "hacer"                    { return HACER; }

 [0-9]+                     { yylval.str = strdup(yytext); return NUM; }
 [a-zA-Z_][a-zA-Z0-9_]*     { yylval.str = strdup(yytext); return ID; }

 .                          ;

%%