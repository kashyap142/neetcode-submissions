class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using pii = pair<int, int>;

        const int n = nums.size();

        unordered_map<int, int> mp;  // val, freq

        for (const int& val : nums) {
            mp[val]++;
        }

        vector<pii> arr(mp.size());

        int i = 0;
        for (auto& pr : mp) {
            arr[i++] = {pr.second, pr.first};  // freq, val
        }

        // sort(arr.begin(), arr.end(), [](const pii& a, const pii& b) { return a.first > b.first;
        // });

        sort(arr.rbegin(), arr.rend());

        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = arr[i].second;
        }

        return ans;
    }
};
