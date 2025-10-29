Enunciado provisional de la primera práctica.

Usando flex crear un programa para procesar procedimientos PL/SQL.

Realizando las operaciones necesarias para que al finalizar el 
procesado permita mostrar las siguientes estadísticas:
- el número argumentos de entrada y de salida.
- el número de variables locales.
- la sentencia de borrado o actualización (UPDATE y DELETE) de mayor longitud.
- el sentencia de consulta (SELECT) con mayor número de tablas y su número.

Los comentarios deberán ser ignorados así como el resto de sentencias. 
Solo deberá tener en cuenta la creación de procedimientos, ignorando 
borrados y actualizaciones

Se valorará el uso de definiciones regulares, correcto uso de
las expresiones regulares, calidad del código, etc.

El analizador debe ser capaz de analizar tanto la entrada estándar 
como un fichero de texto que reciba como argumento.

No se permite utilizar sscanf, strstr (o similares) para realizar análisis léxico 
en el  código C, todo el procesamiento léxico deberá ser realizado con Flex.

------------------------------------------------------------------

Ante una entrada como la siguiente.

CREATE OR REPLACE
  -- Entre paréntesis están los argumentos
PROCEDURE Actualiza_Saldo(cuenta NUMBER, new_saldo NUMBER)
IS
  -- Aquí se encontraría la declaracion de las variables locales
BEGIN
  -- Sentencia de actualización
  UPDATE SALDOS_CUENTAS
    SET SALDO = new_saldo,
    FX_ACTUALIZACION = SYSDATE
    WHERE CO_CUENTA = cuenta;
  -- Sentencia de consulta sobre tabla cliente
  SELECT *
  FROM CLIENTE;
END Actualiza_Saldo;

Debería devolver:
- El procedimiento tiene 2 argumentos.
- El número de variables locales es 0.
- La sentencia de actualización/borrado más larga es:
"UPDATE SALDOS_CUENTAS
    SET SALDO = new_saldo,
    FX_ACTUALIZACION = SYSDATE
    WHERE CO_CUENTA = cuenta"
- La consulta con mayor número de tablas tiene 1 y son: CLIENTE



Ante una entrada como la siguiente.

CREATE PROCEDURE get_user_details
(
    p_user_id IN NUMBER,
    p_user_name OUT VARCHAR2,
    p_user_email OUT VARCHAR2
)
IS 
    v1 VARCHAR2;
    v2 VARCHAR2;
    v3 VARCHAR2;
BEGIN
  SELECT user_name, user_email INTO p_user_name, p_user_email
  FROM users WHERE user_id = p_user_id;

  DBMS_OUTPUT.PUT_LINE(p_user || ' ' || p_user_name );

  v3 := v1 || ' + ' || v2 || ' = ' || UPPER(v1) || ' ' || UPPER(v2);

  SELECT job_id INTO jobid FROM employees WHERE employee_id = empid;

  SELECT AVG(salary), MIN(salary), MAX(salary) INTO avg_sal, min_sal, max_sal
      FROM employees, bosses WHERE job_id = jobid AND emp_id = boss_id;
  
  DELETE FROM customers WHERE last_name = 'Anderson' AND customer_id > 25;

  DELETE FROM suppliers WHERE EXISTS
  ( SELECT customers.customer_name
    FROM customers
    WHERE customers.customer_id = suppliers.supplier_id
    AND customer_id > 25 );
END get_user_details;

Debería devolver:
- El procedimiento tiene 3 argumentos.
- El número de variables locales es 3.
- La sentencia de actualización/borrado más larga es:
"DELETE FROM suppliers WHERE EXISTS
  ( SELECT customers.customer_name
    FROM customers
    WHERE customers.customer_id = suppliers.supplier_id
    AND customer_id > 25 )"
- La consulta con mayor número de tablas tiene 2 y son: employees, bosses
