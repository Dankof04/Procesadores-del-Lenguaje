/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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


#line 103 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    ID = 259,                      /* ID  */
    IMPRIMIR = 260,                /* IMPRIMIR  */
    SI = 261,                      /* SI  */
    SINO = 262,                    /* SINO  */
    MIENTRAS = 263,                /* MIENTRAS  */
    HACER = 264,                   /* HACER  */
    PUNTO_COMA = 265,              /* PUNTO_COMA  */
    PAREN_IZQ = 266,               /* PAREN_IZQ  */
    PAREN_DER = 267,               /* PAREN_DER  */
    LLAVE_IZQ = 268,               /* LLAVE_IZQ  */
    LLAVE_DER = 269,               /* LLAVE_DER  */
    IGUAL = 270,                   /* IGUAL  */
    MAS_IGUAL = 271,               /* MAS_IGUAL  */
    MENOS_IGUAL = 272,             /* MENOS_IGUAL  */
    MULT_IGUAL = 273,              /* MULT_IGUAL  */
    DIV_IGUAL = 274,               /* DIV_IGUAL  */
    SUMA = 275,                    /* SUMA  */
    RESTA = 276,                   /* RESTA  */
    MULT = 277,                    /* MULT  */
    DIV = 278                      /* DIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define ID 259
#define IMPRIMIR 260
#define SI 261
#define SINO 262
#define MIENTRAS 263
#define HACER 264
#define PUNTO_COMA 265
#define PAREN_IZQ 266
#define PAREN_DER 267
#define LLAVE_IZQ 268
#define LLAVE_DER 269
#define IGUAL 270
#define MAS_IGUAL 271
#define MENOS_IGUAL 272
#define MULT_IGUAL 273
#define DIV_IGUAL 274
#define SUMA 275
#define RESTA 276
#define MULT 277
#define DIV 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "parser.y"

    char *str;

#line 206 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_IMPRIMIR = 5,                   /* IMPRIMIR  */
  YYSYMBOL_SI = 6,                         /* SI  */
  YYSYMBOL_SINO = 7,                       /* SINO  */
  YYSYMBOL_MIENTRAS = 8,                   /* MIENTRAS  */
  YYSYMBOL_HACER = 9,                      /* HACER  */
  YYSYMBOL_PUNTO_COMA = 10,                /* PUNTO_COMA  */
  YYSYMBOL_PAREN_IZQ = 11,                 /* PAREN_IZQ  */
  YYSYMBOL_PAREN_DER = 12,                 /* PAREN_DER  */
  YYSYMBOL_LLAVE_IZQ = 13,                 /* LLAVE_IZQ  */
  YYSYMBOL_LLAVE_DER = 14,                 /* LLAVE_DER  */
  YYSYMBOL_IGUAL = 15,                     /* IGUAL  */
  YYSYMBOL_MAS_IGUAL = 16,                 /* MAS_IGUAL  */
  YYSYMBOL_MENOS_IGUAL = 17,               /* MENOS_IGUAL  */
  YYSYMBOL_MULT_IGUAL = 18,                /* MULT_IGUAL  */
  YYSYMBOL_DIV_IGUAL = 19,                 /* DIV_IGUAL  */
  YYSYMBOL_SUMA = 20,                      /* SUMA  */
  YYSYMBOL_RESTA = 21,                     /* RESTA  */
  YYSYMBOL_MULT = 22,                      /* MULT  */
  YYSYMBOL_DIV = 23,                       /* DIV  */
  YYSYMBOL_YYACCEPT = 24,                  /* $accept  */
  YYSYMBOL_list_sntncs = 25,               /* list_sntncs  */
  YYSYMBOL_sntnc = 26,                     /* sntnc  */
  YYSYMBOL_print_stmt = 27,                /* print_stmt  */
  YYSYMBOL_sel_stmt_condition = 28,        /* sel_stmt_condition  */
  YYSYMBOL_sel_stmt = 29,                  /* sel_stmt  */
  YYSYMBOL_30_1 = 30,                      /* $@1  */
  YYSYMBOL_iter_stmt_while = 31,           /* iter_stmt_while  */
  YYSYMBOL_iter_stmt_condition = 32,       /* iter_stmt_condition  */
  YYSYMBOL_iter_stmt_hacer = 33,           /* iter_stmt_hacer  */
  YYSYMBOL_iter_stmt = 34,                 /* iter_stmt  */
  YYSYMBOL_assig_stmt = 35,                /* assig_stmt  */
  YYSYMBOL_36_2 = 36,                      /* $@2  */
  YYSYMBOL_37_3 = 37,                      /* $@3  */
  YYSYMBOL_38_4 = 38,                      /* $@4  */
  YYSYMBOL_39_5 = 39,                      /* $@5  */
  YYSYMBOL_40_6 = 40,                      /* $@6  */
  YYSYMBOL_41_7 = 41,                      /* $@7  */
  YYSYMBOL_42_8 = 42,                      /* $@8  */
  YYSYMBOL_43_9 = 43,                      /* $@9  */
  YYSYMBOL_44_10 = 44,                     /* $@10  */
  YYSYMBOL_expr = 45,                      /* expr  */
  YYSYMBOL_mult_expr = 46,                 /* mult_expr  */
  YYSYMBOL_val = 47                        /* val  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  81

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    63,    70,    73,    76,    79,    79,    86,
      96,   107,   115,   114,   133,   144,   155,   166,   175,   187,
     186,   196,   198,   195,   208,   210,   207,   220,   222,   219,
     232,   234,   231,   247,   253,   259,   266,   272,   278,   285,
     292,   299
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID",
  "IMPRIMIR", "SI", "SINO", "MIENTRAS", "HACER", "PUNTO_COMA", "PAREN_IZQ",
  "PAREN_DER", "LLAVE_IZQ", "LLAVE_DER", "IGUAL", "MAS_IGUAL",
  "MENOS_IGUAL", "MULT_IGUAL", "DIV_IGUAL", "SUMA", "RESTA", "MULT", "DIV",
  "$accept", "list_sntncs", "sntnc", "print_stmt", "sel_stmt_condition",
  "sel_stmt", "$@1", "iter_stmt_while", "iter_stmt_condition",
  "iter_stmt_hacer", "iter_stmt", "assig_stmt", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "expr", "mult_expr", "val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      78,    72,     2,    13,   -36,   -36,    56,    12,   -36,    33,
     -36,    48,    50,   -36,   -36,    53,    54,    68,    74,    75,
      70,    70,   -36,    83,   -36,    78,    70,    82,    78,    70,
     -36,   -36,   -36,   -36,   -36,   -36,    70,     5,   -19,   -36,
      11,   -36,     6,    46,    78,    29,   -13,    70,    70,    70,
      70,    57,   -36,    70,    70,    70,    70,   -36,    89,   -36,
      36,    90,   -13,   -13,   -13,   -13,   -36,   -19,   -19,   -36,
     -36,   -36,   -36,    86,    87,    70,    78,    59,    43,   -36,
     -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       8,    19,     0,     0,    14,    16,     8,     0,     7,     0,
       4,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,     8,     0,     0,     8,     0,
      22,    25,    28,    31,    39,    40,     0,     0,    35,    38,
       0,     3,     8,     0,     8,     8,    20,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,    10,    11,    15,
       8,     0,    23,    26,    29,    32,    41,    33,    34,    36,
      37,    12,    17,     0,     0,     0,     8,     0,     8,    18,
      13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -23,    -6,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -20,   -35,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    10,    74,    11,    27,    12,
      13,    14,    15,    16,    47,    17,    48,    18,    49,    19,
      50,    37,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      23,    40,    42,    55,    56,    45,    43,    53,    54,    46,
       1,     2,     3,    20,     4,     5,    51,    52,    67,    68,
      58,    60,    24,    57,    21,    53,    54,    62,    63,    64,
      65,    53,    54,     1,     2,     3,    23,     4,     5,    23,
       1,     2,     3,    61,     4,     5,    25,     1,     2,     3,
      72,     4,     5,    78,    23,    77,    22,    80,    59,    26,
       1,     2,     3,    28,     4,     5,    53,    54,    29,    66,
      30,    79,    23,    34,    35,    69,    70,    53,    54,    53,
      54,    36,     1,     2,     3,    31,     4,     5,   -21,   -24,
     -27,   -30,    32,    41,    33,    44,    71,    75,    73,     0,
      76
};

static const yytype_int8 yycheck[] =
{
       6,    21,    25,    22,    23,    28,    26,    20,    21,    29,
       4,     5,     6,    11,     8,     9,    36,    12,    53,    54,
      14,    44,    10,    12,    11,    20,    21,    47,    48,    49,
      50,    20,    21,     4,     5,     6,    42,     8,     9,    45,
       4,     5,     6,    14,     8,     9,    13,     4,     5,     6,
      14,     8,     9,    76,    60,    75,     0,    14,    12,    11,
       4,     5,     6,    13,     8,     9,    20,    21,    15,    12,
      16,    12,    78,     3,     4,    55,    56,    20,    21,    20,
      21,    11,     4,     5,     6,    17,     8,     9,    16,    17,
      18,    19,    18,    10,    19,    13,     7,    11,     8,    -1,
      13
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     8,     9,    25,    26,    27,    28,
      29,    31,    33,    34,    35,    36,    37,    39,    41,    43,
      11,    11,     0,    26,    10,    13,    11,    32,    13,    15,
      16,    17,    18,    19,     3,     4,    11,    45,    46,    47,
      45,    10,    25,    45,    13,    25,    45,    38,    40,    42,
      44,    45,    12,    20,    21,    22,    23,    12,    14,    12,
      25,    14,    45,    45,    45,    45,    12,    46,    46,    47,
      47,     7,    14,     8,    30,    11,    13,    45,    25,    12,
      14
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    24,    25,    25,    26,    26,    26,    26,    26,    27,
      28,    29,    30,    29,    31,    32,    33,    34,    34,    36,
      35,    37,    38,    35,    39,    40,    35,    41,    42,    35,
      43,    44,    35,    45,    45,    45,    46,    46,    46,    47,
      47,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     1,     1,     1,     1,     0,     4,
       4,     4,     0,     9,     1,     3,     1,     5,     8,     0,
       4,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     3,     3,     1,     3,     3,     1,     1,
       1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 9: /* print_stmt: IMPRIMIR PAREN_IZQ expr PAREN_DER  */
#line 87 "parser.y"
        {
            printf("\tprint\n"); // Imprime "print" al final de la sentencia
        }
#line 1288 "y.tab.c"
    break;

  case 10: /* sel_stmt_condition: SI PAREN_IZQ expr PAREN_DER  */
#line 97 "parser.y"
        {
            (yyval.str) = new_label();
            printf("\tsifalsovea %s\n", (yyval.str)); // Despues de evaluar la expresión, si es falsa salta a la etiqueta generada
        }
#line 1297 "y.tab.c"
    break;

  case 11: /* sel_stmt: sel_stmt_condition LLAVE_IZQ list_sntncs LLAVE_DER  */
#line 108 "parser.y"
        {
            printf("%s\n", (yyvsp[-3].str)); // Imprime la etiqueta de salida (que era la del salto condicional)
            free((yyvsp[-3].str));
        }
#line 1306 "y.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 115 "parser.y"
        {
            char *lbl_salida = new_label(); //Para no ejecutar el else si la condición fuera verdadera
            printf("\tvea %s\n", lbl_salida); // Al final del if, salta a lbl_salida para evitar ejecutar el else
            printf("%s\n", (yyvsp[-4].str)); // Imprime la etiqueta anterior para comenzar el bloque else
            free((yyvsp[-4].str));
            (yyvsp[-4].str) = lbl_salida; // Guardamos la nueva etiqueta de salida para usarla al final
        }
#line 1318 "y.tab.c"
    break;

  case 13: /* sel_stmt: sel_stmt_condition LLAVE_IZQ list_sntncs LLAVE_DER SINO $@1 LLAVE_IZQ list_sntncs LLAVE_DER  */
#line 123 "parser.y"
        {
            printf("%s\n", (yyvsp[-8].str)); // Por ultimo imprimimos la etiqueta de salida
            free((yyvsp[-8].str));
        }
#line 1327 "y.tab.c"
    break;

  case 14: /* iter_stmt_while: MIENTRAS  */
#line 134 "parser.y"
        {
            (yyval.str) = new_label();
            printf("%s\n", (yyval.str)); // Mostramos la etiqueta del bucle antes de evaluar la expresión
        }
#line 1336 "y.tab.c"
    break;

  case 15: /* iter_stmt_condition: PAREN_IZQ expr PAREN_DER  */
#line 145 "parser.y"
        {
            (yyval.str) = new_label();
            printf("\tsifalsovea %s\n", (yyval.str)); // Una vez evaluada la expresión, viajaremos a la etiqueta de salida si fuera falsa
        }
#line 1345 "y.tab.c"
    break;

  case 16: /* iter_stmt_hacer: HACER  */
#line 156 "parser.y"
        {
            (yyval.str) = new_label();
            printf("%s\n", (yyval.str)); // Creamos la etiqueta del bucle (solo habrá una porque evaluamos al final)
        }
#line 1354 "y.tab.c"
    break;

  case 17: /* iter_stmt: iter_stmt_while iter_stmt_condition LLAVE_IZQ list_sntncs LLAVE_DER  */
#line 167 "parser.y"
        {
            printf("\tvea %s\n", (yyvsp[-4].str)); // Volvemos a la etiqueta del bucle para reevaluar la expresión
            printf("%s\n", (yyvsp[-3].str)); // Imprimimos la etiqueta de salida para cuando la condición del bucle sea falsa
            free((yyvsp[-4].str));
            free((yyvsp[-3].str));
        }
#line 1365 "y.tab.c"
    break;

  case 18: /* iter_stmt: iter_stmt_hacer LLAVE_IZQ list_sntncs LLAVE_DER MIENTRAS PAREN_IZQ expr PAREN_DER  */
#line 176 "parser.y"
        {
            printf("\tsiciertovea %s\n", (yyvsp[-7].str)); // Evaluamos la expresión y si fuera cierta, volveriamos a la etiqueta del principio
            free((yyvsp[-7].str));
        }
#line 1374 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 187 "parser.y"
        { printf("\tvalori %s\n", (yyvsp[0].str)); }
#line 1380 "y.tab.c"
    break;

  case 20: /* assig_stmt: ID $@2 IGUAL expr  */
#line 189 "parser.y"
        {
            printf("\tasigna\n");
            free((yyvsp[-3].str));
        }
#line 1389 "y.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 196 "parser.y"
        { printf("\tvalori %s\n", (yyvsp[0].str)); }
#line 1395 "y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 198 "parser.y"
        { printf("\tvalord %s\n", (yyvsp[-2].str)); }
#line 1401 "y.tab.c"
    break;

  case 23: /* assig_stmt: ID $@3 MAS_IGUAL $@4 expr  */
#line 200 "parser.y"
        {
            printf("\tsum\n");
            printf("\tasigna\n");
            free((yyvsp[-4].str));
        }
#line 1411 "y.tab.c"
    break;

  case 24: /* $@5: %empty  */
#line 208 "parser.y"
        { printf("\tvalori %s\n", (yyvsp[0].str)); }
#line 1417 "y.tab.c"
    break;

  case 25: /* $@6: %empty  */
#line 210 "parser.y"
        { printf("\tvalord %s\n", (yyvsp[-2].str)); }
#line 1423 "y.tab.c"
    break;

  case 26: /* assig_stmt: ID $@5 MENOS_IGUAL $@6 expr  */
#line 212 "parser.y"
        {
            printf("\tsub\n");
            printf("\tasigna\n");
            free((yyvsp[-4].str));
        }
#line 1433 "y.tab.c"
    break;

  case 27: /* $@7: %empty  */
#line 220 "parser.y"
        { printf("\tvalori %s\n", (yyvsp[0].str)); }
#line 1439 "y.tab.c"
    break;

  case 28: /* $@8: %empty  */
#line 222 "parser.y"
        { printf("\tvalord %s\n", (yyvsp[-2].str)); }
#line 1445 "y.tab.c"
    break;

  case 29: /* assig_stmt: ID $@7 MULT_IGUAL $@8 expr  */
#line 224 "parser.y"
        {
            printf("\tmul\n");
            printf("\tasigna\n");
            free((yyvsp[-4].str));
        }
#line 1455 "y.tab.c"
    break;

  case 30: /* $@9: %empty  */
#line 232 "parser.y"
        { printf("\tvalori %s\n", (yyvsp[0].str)); }
#line 1461 "y.tab.c"
    break;

  case 31: /* $@10: %empty  */
#line 234 "parser.y"
        { printf("\tvalord %s\n", (yyvsp[-2].str)); }
#line 1467 "y.tab.c"
    break;

  case 32: /* assig_stmt: ID $@9 DIV_IGUAL $@10 expr  */
#line 236 "parser.y"
        {
            printf("\tdiv\n");
            printf("\tasigna\n");
            free((yyvsp[-4].str));
        }
#line 1477 "y.tab.c"
    break;

  case 33: /* expr: expr SUMA mult_expr  */
#line 248 "parser.y"
        {
            printf("\tsum\n"); // Al encontrar una suma, imprimimos dicha operación
        }
#line 1485 "y.tab.c"
    break;

  case 34: /* expr: expr RESTA mult_expr  */
#line 254 "parser.y"
        {
            printf("\tsub\n"); // Lo mismo con la resta
        }
#line 1493 "y.tab.c"
    break;

  case 36: /* mult_expr: mult_expr MULT val  */
#line 267 "parser.y"
        {
            printf("\tmul\n"); // Al encontrar una multiplicación, imprimimos dicha operación
        }
#line 1501 "y.tab.c"
    break;

  case 37: /* mult_expr: mult_expr DIV val  */
#line 273 "parser.y"
        {
            printf("\tdiv\n"); // Lo mismo con la división
        }
#line 1509 "y.tab.c"
    break;

  case 39: /* val: NUM  */
#line 286 "parser.y"
        {
            printf("\tmete %s\n", (yyvsp[0].str)); // Imprimimos el mete con el valor del número
            free((yyvsp[0].str));
        }
#line 1518 "y.tab.c"
    break;

  case 40: /* val: ID  */
#line 293 "parser.y"
        {
            printf("\tvalord %s\n", (yyvsp[0].str)); // Imprimimos el valord con el valor del identificador
            free((yyvsp[0].str));
        }
#line 1527 "y.tab.c"
    break;


#line 1531 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 304 "parser.y"



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
