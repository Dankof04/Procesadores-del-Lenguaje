[Español](#-español) | [English](#-english)

---

## 🇪🇸 Español

# Analizador Léxico de Procedimientos SQL (con Flex) 🚀

Este proyecto es un analizador léxico, escrito en **Flex**, diseñado para procesar ficheros de procedimientos almacenados de SQL (similar a PL/SQL de Oracle). Su objetivo principal no es validar la sintaxis completa de SQL, sino **extraer estadísticas específicas** sobre la estructura y contenido de los procedimientos.

## 📊 Características Principales

El analizador está configurado para:

* **Ignorar Mayúsculas/Minúsculas**: Gracias a `%option caseless`, el análisis no distingue entre `SELECT` y `select`.
* **Manejar Comentarios**: Ignora comentarios de una sola línea (`-- ...`) y maneja comentarios multilínea (`/* ... */`) de forma robusta, incluso si se encuentran en medio de una sentencia.
* **Contar Argumentos**: Detecta la definición de un `PROCEDURE` y cuenta cuántos argumentos se le pasan.
* **Contar Variables Locales**: Cuenta el número de variables declaradas en la sección `IS/AS` antes del `BEGIN`.
* **Analizar Sentencias `SELECT`**: Identifica la sentencia `SELECT` que consulta el **mayor número de tablas** y almacena la lista de dichas tablas.
* **Analizar Sentencias `UPDATE` y `DELETE`**: Encuentra la sentencia `UPDATE` o `DELETE` **más larga** (por número de caracteres) y almacena su texto completo.

---

## ⚙️ Funcionamiento Interno: Una Máquina de Estados

El analizador funciona como una **máquina de estados finitos**. Comienza en el estado `INITIAL` y transita a otros estados a medida que reconoce patrones (tokens) en el código de entrada.

### Estados Definidos

* `INITIAL`: El estado por defecto. Busca el inicio de un procedimiento (`PROCEDURE ... (`).
* `COM`: Estado para manejar comentarios multilínea (`/* ... */`).
* `ARGS`: Estado para contar los argumentos del procedimiento.
* `VARS`: Estado para contar las variables locales.
* `BODY`: Estado principal que procesa el cuerpo (lógica) del procedimiento.
* `SELECT`: Estado específico para analizar las tablas de una sentencia `SELECT`.
* `UPDATE`: Estado para procesar una sentencia `UPDATE`.
* `DELETE`: Estado para procesar una sentencia `DELETE`.

### Flujo de Ejecución

1.  **Manejo de Comentarios (Estado `COM`)**:
    * En cualquier estado (`<*>`), si se detecta `/*`, el analizador usa `yy_push_state(COM)` para "recordar" dónde estaba y salta al estado `COM`.
    * En el estado `COM`, ignora todo el texto hasta que encuentra `*/`, momento en el que usa `yy_pop_state()` para regresar al estado anterior (ya sea `BODY`, `ARGS`, etc.).
    * Los comentarios `--` se ignoran directamente.

2.  **Definición del Procedimiento (Estados `INITIAL` -> `ARGS` -> `VARS`)**:
    * En `INITIAL`, al encontrar `PROCEDURE nombre (...)`, cambia al estado `ARGS`.
    * En `ARGS`, incrementa `contador_argumentos` por cada identificador que encuentra, ya sea seguido de coma (`,`) o de un paréntesis de cierre (`)`).
    * Al encontrar `IS` o `AS`, transita al estado `VARS`.
    * En `VARS`, incrementa `contador_variables` por cada declaración (asumida como `nombre_var tipo;`).
    * Al encontrar `BEGIN`, el analizador entra en el cuerpo del procedimiento, pasando al estado `BODY`.

3.  **Cuerpo del Procedimiento (Estado `BODY`)**:
    * Este es el estado "central". Desde aquí, el analizador busca las sentencias de interés:
    * **`SELECT ... FROM`**: Al detectarse, cambia al estado `SELECT`.
    * **`UPDATE` / `DELETE`**: Utiliza un operador de *lookahead* (`/UPDATE`, `/DELETE`) para detectar la palabra clave sin consumirla, y cambia al estado `UPDATE` o `DELETE` correspondiente.
    * **`END ... ;`**: Al encontrar el final del bloque, regresa al estado `INITIAL` para buscar el siguiente procedimiento.

4.  **Análisis de `SELECT` (Estado `SELECT`)**:
    * Este estado está diseñado para contar tablas entre `FROM` y `WHERE` o `;`.
    * Utiliza `yymore()` para acumular el texto de todas las tablas en el búfer `yytext`.
    * Cuenta las tablas (`contador_tablas`) separadas por comas.
    * Al encontrar el final de la lista de tablas (detectado por un *lookahead* de `/;` o `/WHERE`), usa `strdup(yytext)` para guardar la lista de tablas actual en `tablas_text`.
    * Cuando finalmente consume el `;` o `WHERE`, compara el `contador_tablas` actual con `max_tablas`. Si es mayor, actualiza `max_tablas` y guarda la lista de tablas en `max_tablas_text`.
    * Finalmente, resetea `contador_tablas` y regresa a `BODY`.

5.  **Análisis de `UPDATE` / `DELETE` (Estados `UPDATE`, `DELETE`)**:
    * Una vez en estos estados, consume toda la sentencia hasta encontrar un punto y coma (`;`).
    * Obtiene la longitud de la sentencia con `yyleng`.
    * Compara esta longitud con `max_long_up_del`. Si es mayor, actualiza el máximo y guarda el texto de la sentencia (`strdup(yytext)`) en `max_long_text`.
    * Regresa al estado `BODY` para seguir analizando.

---

## 💻 Cómo Compilar y Usar

Para utilizar este analizador, necesitas tener **Flex** y un compilador de C (como **GCC**) instalados.

### 1. Compilación

Asumiendo que has guardado el código como `analizador.l`:

1.  **Generar el código C con Flex**:
    ```bash
    flex analizador.l
    ```
    Esto creará un fichero llamado `lex.yy.c`.

2.  **Compilar el código C con GCC**:
    ```bash
    gcc lex.yy.c -o analizador -lfl
    ```
    * `-o analizador`: Crea un ejecutable llamado `analizador`.
    * `-lfl`: Enlaza la biblioteca de Flex (necesaria para `yywrap` y otras funciones).

### 2. Ejecución

Puedes ejecutar el analizador de dos maneras:

* **Pasando un fichero como argumento**:
    ```bash
    ./analizador mi_procedimiento.sql
    ```

* **Usando la entrada estándar (stdin)**:
    ```bash
    cat mi_procedimiento.sql | ./analizador
    ```

---

## 📄 Salida del Programa

Tras procesar el fichero (o la entrada estándar), el programa imprimirá en la consola un resumen de las estadísticas recopiladas:


* **Número de argumentos**: Total de argumentos contados en la definición del `PROCEDURE`.
* **Número de variables locales**: Total de variables contadas entre `IS/AS` y `BEGIN`.
* **La operación UPDATE o DELETE...**: Muestra el texto completo de la sentencia `UPDATE` o `DELETE` más larga encontrada.
* **La consulta SELECT con más tablas...**: Indica el número máximo de tablas encontrado en una sola consulta `SELECT` y la lista de esas tablas.

---

## 🇬🇧 English

# SQL Procedure Lexical Analyzer (with Flex) 🚀

This project is a lexical analyzer, written in **Flex**, designed to process SQL stored procedure files (similar to Oracle's PL/SQL). Its main goal is not to validate the entire SQL syntax, but to **extract specific statistics** about the structure and content of the procedures.

## 📊 Key Features

The analyzer is configured to:

* **Case Insensitive**: Thanks to `%option caseless`, the analysis doesn't distinguish between `SELECT` and `select`.
* **Comment Handling**: Ignores single-line (`-- ...`) and multi-line (`/* ... */`) comments robustly, even if they appear in the middle of a statement.
* **Argument Counting**: Detects a `PROCEDURE` definition and counts its arguments.
* **Local Variable Counting**: Counts the number of variables declared in the `IS/AS` section before the `BEGIN`.
* **SELECT Statement Analysis**: Identifies the `SELECT` statement that queries the **most tables** and stores that list of tables.
* **UPDATE and DELETE Analysis**: Finds the **longest** `UPDATE` or `DELETE` statement (by character count) and stores its full text.

---

## ⚙️ How It Works: A State Machine

The analyzer operates as a **finite state machine**. It starts in the `INITIAL` state and transitions to other states as it recognizes patterns (tokens) in the input code.

### Defined States

* `INITIAL`: The default state. Looks for the start of a procedure (`PROCEDURE ... (`).
* `COM`: State for handling multi-line comments (`/* ... */`).
* `ARGS`: State for counting procedure arguments.
* `VARS`: State for counting local variables.
* `BODY`: The main state that processes the procedure's body (logic).
* `SELECT`: Specific state for analyzing tables in a `SELECT` statement.
* `UPDATE`: State for processing an `UPDATE` statement.
* `DELETE`: State for processing a `DELETE` statement.

### Execution Flow

1.  **Comment Handling (COM State)**:
    * In any state (`<*>`), if `/*` is detected, the analyzer uses `yy_push_state(COM)` to "remember" its location and jumps to the `COM` state.
    * In the `COM` state, it ignores all text until it finds `*/`, at which point it uses `yy_pop_state()` to return to the previous state (be it `BODY`, `ARGS`, etc.).
    * Single-line `--` comments are ignored directly.

2.  **Procedure Definition (INITIAL -> ARGS -> VARS States)**:
    * In `INITIAL`, upon finding `PROCEDURE name (...)`, it switches to the `ARGS` state.
    * In `ARGS`, it increments `contador_argumentos` (argument counter) for each identifier it finds, whether followed by a comma (`,`) or a closing parenthesis (`)`).
    * Upon finding `IS` or `AS`, it transitions to the `VARS` state.
    * In `VARS`, it increments `contador_variables` (variable counter) for each declaration (assumed to be `var_name type;`).
    * Upon finding `BEGIN`, the analyzer enters the procedure body, moving to the `BODY` state.

3.  **Procedure Body (BODY State)**:
    * This is the "central" state. From here, the analyzer looks for statements of interest:
    * **`SELECT ... FROM`**: When detected, it changes to the `SELECT` state.
    * **`UPDATE` / `DELETE`**: It uses a *lookahead* operator (`/UPDATE`, `/DELETE`) to detect the keyword without consuming it, then changes to the corresponding `UPDATE` or `DELETE` state.
    * **`END ... ;`**: Upon finding the end of the block, it returns to the `INITIAL` state to look for the next procedure.

4.  **SELECT Analysis (SELECT State)**:
    * This state is designed to count tables between `FROM` and `WHERE` or `;`.
    * It uses `yymore()` to accumulate the text of all tables in the `yytext` buffer.
    * It counts the tables (`contador_tablas`) separated by commas.
    * Upon reaching the end of the table list (detected by a *lookahead* for `/;` or `/WHERE`), it uses `strdup(yytext)` to save the current table list to `tablas_text`.
    * When it finally consumes the `;` or `WHERE`, it compares the current `contador_tablas` with `max_tablas`. If it's greater, it updates `max_tablas` and saves the table list to `max_tablas_text`.
    * Finally, it resets `contador_tablas` and returns to `BODY`.

5.  **UPDATE / DELETE Analysis (UPDATE, DELETE States)**:
    * Once in these states, it consumes the entire statement up to a semicolon (`;`).
    * It gets the statement's length with `yyleng`.
    * It compares this length with `max_long_up_del`. If it's greater, it updates the maximum and saves the statement text (`strdup(yytext)`) to `max_long_text`.
    * It returns to the `BODY` state to continue parsing.

---

## 💻 How to Compile and Use

To use this analyzer, you need **Flex** and a C compiler (like **GCC**) installed.

### 1. Compilation

Assuming you saved the code as `analyzer.l`:

1.  **Generate the C code with Flex**:
    ```bash
    flex analyzer.l
    ```
    This will create a file named `lex.yy.c`.

2.  **Compile the C code with GCC**:
    ```bash
    gcc lex.yy.c -o analyzer -lfl
    ```
    * `-o analyzer`: Creates an executable named `analyzer`.
    * `-lfl`: Links the Flex library (necessary for `yywrap` and other functions).

### 2. Execution

You can run the analyzer in two ways:

* **Passing a file as an argument**:
    ```bash
    ./analyzer my_procedure.sql
    ```

* **Using standard input (stdin)**:
    ```bash
    cat my_procedure.sql | ./analyzer
    ```

---

## 📄 Program Output

After processing the file (or stdin), the program will print a summary of the collected statistics to the console:

* **Number of arguments**: Total arguments counted in the `PROCEDURE` definition.
* **Number of local variables**: Total variables counted between `IS/AS` and `BEGIN`.
* **The longest UPDATE or DELETE...**: Shows the full text of the longest `UPDATE` or `DELETE` statement found.
* **The SELECT query with the most tables...**: Indicates the maximum number of tables found in a single `SELECT` query and lists those tables.
