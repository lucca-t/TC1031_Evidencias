class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vuelo mas barato de A a B con maximo K paradas
        // BFS? 
        // Checar todo dentro de K niveles

        // Guardará el costo para alcanzar cada nodo
        vector<int> minCost (n, INT_MAX);
        minCost[src] = 0;
        // Solo vamos hasta k+1 porque esa es la cantidad de paradas maxima
        
        // O(k)
        for(int i = 0; i <= k; i++) {
            // Copia para no sobreescribir los valores de minCost
            vector<int> tempCost(minCost);

            // O(E)
            for (auto& flight : flights) {
                if (minCost[flight[0]] != INT_MAX) {
                    // Checamos si llegar a este destino sale mas barato que tomar la ruta previa
                    tempCost[flight[1]] = min( tempCost[flight[1]], minCost[ flight[0] ] + flight[2] );
                }
            }
            minCost = tempCost;
        }

        // Tiempo O(K * E) Espacio O(N)
        if (minCost[dst] == INT_MAX) {
            return -1;
        } else {
            return minCost[dst];
        }

        
    }
};
