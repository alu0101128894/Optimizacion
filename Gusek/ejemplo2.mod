/*
Este es mi segundo programa en GUSEK
Vamos a resolver un problema anterior donde parametrizamos los datos y los separamos del modelo.
*/
#Definici�n de par�metros
param c{1..3};
param A{1..2, 1..3};
param b{1..2};
# Definición de las variables
var x{1..3}, >= 0;
# Función objetivo
minimize z: c[1]*x[1] + c[2]*x[2] + c[3]*x[3];
# Restricciones
r1: A[1,1]*x[1] + A[1,2]*x[2] + A[1,3]*x[3] = b[1];
r2: A[2,1]*x[1] + A[2,2]*x[2] + A[2,3]*x[3] = b[2];
# Lo solucionamos y mostramos los resultados
solve;
display x;
# Proporcionamos los datos del problema (Par�metros c, A y b)
data;
# Al definir un vector indicamos los �ndices
param c:= 1 4
          2 -2
          3 2;

param b:= 1 4
          2 2;

param A:   1 2 3 :=
         1 0 6 1
         2 1 -1 0;

end;
