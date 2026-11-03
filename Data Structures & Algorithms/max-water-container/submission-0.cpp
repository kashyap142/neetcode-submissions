class Solution {
   public:
    int maxArea(vector<int>& nums) {
        const int n = nums.size();

        int ans = -1;
        int i = 0, j = n - 1;

        while (i < j) {
            ans = max(ans, (j - i) * min(nums[i], nums[j]));

            if (nums[i] <= nums[j]) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};
