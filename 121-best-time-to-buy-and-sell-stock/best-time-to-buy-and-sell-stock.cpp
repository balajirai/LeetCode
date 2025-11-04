class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, profit_max = 0, profit, price_min = INT_MAX;
        for(; i<prices.size(); i++){
            profit = prices[i] - price_min;
            price_min = min(prices[i], price_min);
            profit_max = max(profit,profit_max);
        }
        return profit_max;
    }
};