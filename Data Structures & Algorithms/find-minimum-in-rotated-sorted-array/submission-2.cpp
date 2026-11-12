class Solution {
   public:
    int findMin(vector<int>& nums) {
        const int n = nums.size();

        int l = 0, r = n - 1;

        while (l < r) {
            int m = (l + r) / 2;

            if (nums[r] > nums[m]) {  // sorted part, skip it except the mid
                r = m;
            } else {
                l = m + 1;
            }
        }

        return nums[l];
    }
};
