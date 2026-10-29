class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minStockValueTillNow = INT_MAX;

        for(const int &price : prices) {
            profit = max(profit, price - minStockValueTillNow);
            minStockValueTillNow = min(minStockValueTillNow, price);
        }

        return profit;
    }
};
