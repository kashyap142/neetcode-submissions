class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;

        for(const int &val: nums) {
            mp[val]++;
        }

        const int n = nums.size();
        vector<vector<int>>cnt(n + 1);

        for(auto &pr: mp) {
            cnt[pr.second].push_back(pr.first);
        }

        vector<int>ans;
        for(int i = n; i >= 0; i--) {
            for(auto &val: cnt[i]) {
                ans.push_back(val);
                if(ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
