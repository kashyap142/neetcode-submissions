class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int ans = 0;
        vector<int>pre(n);

        for(int i = n - 2; i >= 0; i--) {
            pre[i] = max(pre[i + 1], prices[i + 1]);
        }

        for(int i = 0; i < n; i++) {
            // cout << pre[i] << ' ';
            ans = max(ans, pre[i] - prices[i]);
        }

        return ans;
    }
};
