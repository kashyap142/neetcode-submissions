class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();

        using pii = pair<int, int>;
        vector<pii> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        int i = 0, j = n - 1;

        while (i < j) {
            int sum = arr[i].first + arr[j].first;

            if (sum == target) {
                vector<int>ans = {arr[i].second, arr[j].second};
                sort(ans.begin(), ans.end());
                return ans;
            } else if (sum > target) {
                j--;
            } else
                i++;
        }

        return {-1, -1};
    }
};
