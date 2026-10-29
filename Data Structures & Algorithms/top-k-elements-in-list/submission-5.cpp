class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using pii = pair<int, int>;
        const int n = nums.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        unordered_map<int, int> mp;
        for (auto& val : nums) {
            mp[val]++;
        }

        for (auto& pr : mp) {
            pq.push({pr.second, pr.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};
