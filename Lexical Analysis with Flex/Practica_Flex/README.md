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
