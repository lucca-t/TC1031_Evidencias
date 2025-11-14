class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // cantidad minima de monedas
        // dos opciones, usar moneda o no
        // empezar con la mas grande y bajar
        int numCoins = 0;
        int currentAmount = 0;
        // Greedy no sirve
        // Crear dp
        // Usando un valor de amount + 1 porque al momento esa cantidad es imposible
        vector<int> dp (amount + 1, amount + 1);
        dp[0] = 0;

        // Llenar dp con numero de monedas necesarias para conseguir ese cantidad de dinero

        // O(a)
        for (int i = 1; i <= amount; i++) {
            // O(c)
            for (int j = 0; j < coins.size(); j++) {
                // Checar que este dentro del rango
                if (i - coins[j] >= 0){
                    // Checar si usar la moneda actual es mas eficiente o no
                    dp[i] = min( dp[i], 1 + dp[i - coins[j]] );
                }
            }
        }
        
        // Tiempo O(a * c) Espacio O(a)
        if ( dp[amount] != amount + 1) {
            return dp[amount];
        } else {
            return -1;
        }
    }
};
