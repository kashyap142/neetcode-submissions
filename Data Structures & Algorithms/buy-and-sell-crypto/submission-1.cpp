class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = INT_MAX;

        for(const int &price : prices) {
            ans = max(ans, price - mini);
            mini = min(mini, price);
        }

        return ans;
    }
};
