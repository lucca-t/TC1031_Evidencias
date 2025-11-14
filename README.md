# TC1031_Evidencias

## Problema 1: Algoritmo de Ordenamiento
### LeetCode #148 – Sort List [Video](https://youtu.be/PFgjR-Wn6i8)

En este primer problema, LeetCode #148 se tiene que ordenar una lista ligada sin usar una estructura de datos adicional como un vector. La resolví usando un merge sort para cumplir con las restricciones de **tiempo O(n log n) y espacio O(1) adicional.**

Se usa una versión adaptada del algoritmo de merge sort, lo que cambia es usar un apuntador rápido y lento, cuando el rápido llegue al final de la lista el lento está a la mitad de la lista. Esto nos permite conseguir la mitad sin acceso aleatorio como en un vector. Usando esta división se puede dividir recursivamente y ordernar las mitades, cambiando a donde apuntan los apuntadores para combinar hasta lograr un resultado final ordenado.

## Problema 2: Estructuras lineales
### LeetCode #322 – Coin Change [Video](https://youtu.be/zFbhotuf5nY)

En este problema se pide determinar el mínimo número de monedas necesarias para formar una cantidad específica a partir de un conjunto de denominaciones disponibles.

Para resolverlo, apliqué un enfoque de programación dinámica (DP) con una estructura lineal (un arreglo 1D), en el cual cada posición representa el número mínimo de monedas necesario para formar una cantidad determinada. Llenando este arreglo de DP se hace on tabulación. Checando cada cantidad de dinero secuencialmente hasta el "amount" para conseguir la cantidad mínima de monedas. La clave es este fórmula. 

`dp[i] = min(dp[i], dp[i - coin] + 1)`

Esto checa si conviene usar la combinación actual, o si conviene usar una moneda, y la combinación previa. Haciendo esto para cada cantidad hasta nuestro "amount" resultará en la combinación óptima en tiempo y espacio lineal. 

La complejidad sería **Tiempo: O(a * c) y Espacio O(a).** a siendo "amount" y c siendo las cantidad de denominaciones de las monedas.

## Problema 3: Estructuras NO lineales
### LeetCode #787 – Cheapest Flights Within K Stops [Video](https://youtu.be/9rTSMvoytDE)

En este problema se pide determinar la manera mas económica de conectar dos ciudades con máximo K paradas. Es un problema de grafos donde encontrar el cámino mas bárato se puede resolver de muchas maneras. 
Para resolverlo, use una versión modificadad de Bellman-Ford por ser mejor que un BFS simple y mas fácil de implementar para esta solución que Dijkstra's. Se usa una lista empezando con valores de infinito excepto por el inicio para tomar en cuenta la manera mas barata para alcanzar una ciudad en específico, y después se checa K+1 veces todas las conexiones de vuelos para ver si hay una mejor manera usando alguna otra ruta.
`tempCost[flight[1]] = min( tempCost[flight[1]], minCost[ flight[0] ] + flight[2] )`
Al final, si el destino sigue siendo infinito, no hay ruta válida y se retorna -1. Si hay algo se retorna el valor dado ya sabiendo que es la manera mas barata.

La complejidad sería de **Espacio O(N) Tiempo O(K * E)** N siendo la cantidad de destinos, K siendo el número de paradas, y E siendo la cantidad de vuelos. 
