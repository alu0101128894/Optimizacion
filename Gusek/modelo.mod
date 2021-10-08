/* 
Resuelve un problema de Programacion Lineal que está en su forma
estándar */

#Parametros
param m, integer, >0; #Nº restricciones
param n, integer, >0; #Nº variables
set I:= {1..m};
set J:= {1..n};
param c {J};
param b {I};
param A {I,J};
#Variables
var x{J}, >=0;
#Funcion Objetivo
minimize z: sum {j in J} c[j] * x[j];
#Restricciones
r {i in I}: sum {j in J} A [i,j] * x[j] = b[i];
#Solucionamos
solve; 
display x, z;

data; 

param m:= 2;
param n:= 3;
param c:= 1  4
          2 -2
          3  2;

param b:= 1  4
          2  2;

param A:    1  2  3 :=
         1  0  6  1
         2  1 -1  0;
end;
