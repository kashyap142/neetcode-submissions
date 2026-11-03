class Solution {
   public:
    int trap(vector<int>& nums) {
        const int n = nums.size();

        vector<int> pre(n), suf(n);
        pre.front() = nums.front(), suf.back() = nums.back();

        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
            suf[n - 1 - i] = max(suf[n - i], nums[n - 1 - i]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += min(pre[i], suf[i]) - nums[i];
        }

        return ans;
    }
};
