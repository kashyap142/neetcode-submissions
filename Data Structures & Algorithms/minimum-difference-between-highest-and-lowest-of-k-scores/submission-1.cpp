class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        for(int i = 0; i <= n - k; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans == INT_MAX? 0 : ans;
    }
};

/*
1 4 7 9

0 1 2 3

1 -> 3 ()

*/