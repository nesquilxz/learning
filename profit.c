int maxProfit(int* prices, int pricesSize) {
    int min_price = prices[0];
    int max_profit = 0;
    int i;

    for (i = 1; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else {
            int profit = prices[i] - min_price;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
    }

    return max_profit;
}
