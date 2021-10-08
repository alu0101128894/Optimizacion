/* 
Este es mi primer programa en GUSEK
Vamos a resolver un problema de programación lineal sencillo 
*/
# Definición de las variables
param c{1..4};
param A{1..2, 1..3};
param b{1..2};
# Función objetivo
minimize z: 2*x1 - 2*x2 + 2*x3 -4*x4;
/* z = Variable del min */
# Restricciones (2 restricciones) R1 y R2
r1: 3*x1      + 1*x3 +4*x4= 46;
r2: x1   - x2        -2*x4= 17;
r3: x1  +2*x2 + 3*x3 + 2*x4=73;
# Lo solucionamos y mostramos los resultados
solve;
display x1, x2, x3, z;
end;
