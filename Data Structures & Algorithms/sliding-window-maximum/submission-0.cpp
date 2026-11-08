class Solution {
    using pii = pair<int, int>;

   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();

        vector<int> ans;
        ans.reserve(n);

        priority_queue<pii> pq;  // val, ind

        int l = 0, r = 0;
        while (r < n) {
            if (r < k - 1) {
                pq.push({nums[r], r});
                r++;
                continue;
            }

            pq.push({nums[r], r});

            while (!pq.empty() && pq.top().second < l) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
            r++, l++;
        }

        return ans;
    }
};
