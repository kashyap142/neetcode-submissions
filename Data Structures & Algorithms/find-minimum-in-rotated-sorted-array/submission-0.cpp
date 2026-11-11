class Solution {
   public:
    int findMin(vector<int>& nums) {
        const int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                return nums[i];
            }
        }

        return nums.front();
    }
};
