# Definición de las variables
var x1 >= 100;
var x2 >= 60;
var x3 >= 60;
# Función objetivo
maximize z: 2*x1 +2*x2 + 4*x3;
/* z = Variable del min */
r1: 1*x2 + 2*x3 <= 240;
r2: 1*x1 + 1*x2 + 1*x3 <=400;
r3: 3*x1 + 1*x2 + 1*x3 <=360;

# Lo solucionamos y mostramos los resultados
solve;
display x1, x2, x3, z;
end;
