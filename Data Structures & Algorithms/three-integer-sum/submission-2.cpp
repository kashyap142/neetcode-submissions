class Solution {
   private:
    void findTriplet(const vector<int>& nums, const int& x, set<vector<int>>& mp) {
        const int t = -nums[x];

        int i = x + 1, j = nums.size() - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum == t) {
                vector<int> k = {-t, nums[i], nums[j]};
                sort(k.begin(), k.end());
                mp.insert(k);
                i++, j--;
            } else if (sum > t) {
                j--;
            } else {
                i++;
            }
        }
    }

   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();

        sort(nums.begin(), nums.end());
        set<vector<int>> mp;

        for (int i = 0; i < n - 2; i++) {
            findTriplet(nums, i, mp);
        }

        vector<vector<int>> ans(mp.begin(), mp.end());

        return ans;
    }
};
