class Solution {
   public:
    int maxProfit(vector<int>& nums) {
        const int n = nums.size();

        int maxi = nums.back(), ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, maxi - nums[i]);
            maxi = max(maxi, nums[i]);
        }

        return ans;
    }
};
