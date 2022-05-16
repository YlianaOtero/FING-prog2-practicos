/*Ejercicio 3 Rayuela
En una hilera de una calle con adoquines unos niños juegan a la rayuela.
Los movimientos permitidos del juego son:
-Al principio del juego los niños se ubican en el adoquín 0.
-De un adoquín numerado i se puede saltar al adoquín numerado i + 1.
-De un adoquín numerado i se puede saltar al adoquín numerado i + 2 (sin pasar por el adoquín i + 1).
Implemente un algoritmo recursivo que calcule el número de caminos posibles para alcanzar un adoquín
objetivo numerado con n (mayor que cero). Asuma que la cantidad de caminos para llegar al adoquin 0 es 1.
Por ejemplo, el número de caminos posibles para n=3 es 3 y son los siguientes: (0,1,2,3), (0,2,3) y (0,1,3). 
Calcule la cantidad de caminos para n desde 1 hasta 10. */

typedef unsigned int uint;

uint caminos(uint n) {
    uint respuesta = 1; //para los casos base n = 0 y n = 1
    if (n > 1) respuesta = caminos(n-1) + caminos(n-2); //casos recursivos
    return respuesta;
}
