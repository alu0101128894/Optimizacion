/* Problema del Transporte*/
#Parámetros

param m, integer, >0; #Números  de almacenes
param n, integer, >0; #Número de mercados

set I:={1..m}; #Conjunto de almacenes
set J:={1..n}; #Conjunto de mercados

param a{I};
param b{J};
param c{I,J};

#Variables
var x{I,J} >=0;
#Funcion objetivo
minimize z: sum{i in I, j in J} c[i,j] * x[i,j]; # Coste total de transporte
#Restricciones
s.t. oferta{i in I}: sum{j in J} x[i,j] = a[i]; # La oferta del origen i es a[i]
s.t. demanda{j in J}: sum{i in I} x[i,j] = b[j]; # La demanda del destino j es b[j] 
s.t. cota{i in I, j in J}: x[i,j] <= K;
#Solucionamos
solve;
display x, z;
#Datos
data; 
param m:= 3;
param n:= 5;
param K: 30;

param a:= 1 38
		  2 44
		  3 69;

param b:= 1 43
		  2 29
		  3 37
		  4 14
		  5 28;

param c:    1 2 3 4 5 :=
			1 3 5 2 4 6
			2 5 2 7 6 3
			3 4 6 8 9 5;
end;
