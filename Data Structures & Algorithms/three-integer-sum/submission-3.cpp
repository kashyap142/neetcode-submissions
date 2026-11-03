class Solution {
   private:
    void findTriplet(const vector<int>& nums, const int& x, vector<vector<int>>& mp) {
        const int t = -nums[x];

        int i = x + 1, j = nums.size() - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum == t) {
                mp.push_back({-t, nums[i], nums[j]});
                i++, j--;

                while (i < j && nums[i] == nums[i - 1]) {
                    i++;
                }
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
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            if(nums[i] > 0) break; // since target is 0, array is increasing

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            findTriplet(nums, i, ans);
        }

        return ans;
    }
};

/*

nums=[-1,0,1,2,-1,-4]

-1, -1, 0, 1, 2, 4

*/