# TC1031_Evidencias

## Problema 1: Algoritmo de Ordenamiento

### [Primer Video](https://youtu.be/PFgjR-Wn6i8)

En este primer problema, LeetCode #148 se tiene que ordenar una lista ligada sin usar una estructura de datos adicional como un vector. La resolví usando un merge sort para cumplir con los requisitos de tiempo O(n logn) y de espacio O(1). 

Se usa una versión adaptada del algoritmo de merge sort, lo que cambia es usar un apuntador rápido y lento, cuando el rápido llegue al final de la lista el lento está a la mitad de la lista. Esto nos permite conseguir la mitad sin acceso aleatorio como en un vector. Usando esta división se puede dividir recursivamente y ordernar las mitades, cambiando a donde apuntan los apuntadores para combinar hasta lograr un resultado final ordenado.

## Problema 2: Estructuras lineales
### [Primer Video](https://youtu.be/zFbhotuf5nY)

En este problema se pide determinar el mínimo número de monedas necesarias para formar una cantidad específica a partir de un conjunto de denominaciones disponibles.

Para resolverlo, apliqué un enfoque de programación dinámica (DP) con una estructura lineal (un arreglo 1D), en el cual cada posición representa el número mínimo de monedas necesario para formar una cantidad determinada. Llenando este arreglo de DP se hace on tabulación. Checando cada cantidad de dinero secuencialmente hasta el "amount" para conseguir la cantidad mínima de monedas. La clave es este fórmula. 

`dp[i] = min(dp[i], dp[i - coin] + 1)`

Esto checa si conviene usar la combinación actual, o si conviene usar una moneda, y la combinación previa. Haciendo esto para cada cantidad hasta nuestro "amount" resultará en la combinación óptima en tiempo y espacio lineal. 

La complejidad sería Tiempo: O(a * c) y Espacio O(a). a siendo "amount" y c siendo las cantidad de denominaciones de las monedas.
