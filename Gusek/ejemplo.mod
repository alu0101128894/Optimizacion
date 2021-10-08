/* 
Este es mi primer programa en GUSEK
Vamos a resolver un problema de programación lineal sencillo 
*/
# Definición de las variables
var x1 >= 0, integer;
var x2 >= 0;
var x3 >= 0;
# Función objetivo
minimize z: 4*x1 - 2*x2 + 2*x3;
/* z = Variable del min */
# Restricciones (2 restricciones) R1 y R2
r1:     6*x2 + x3 = 4;
r2: x1  - x2      = 2;
# Lo solucionamos y mostramos los resultados
solve;
display x1, x2, x3, z;
end;
