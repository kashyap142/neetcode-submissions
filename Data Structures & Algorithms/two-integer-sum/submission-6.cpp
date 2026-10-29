class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const size_t n = nums.size();
        unordered_map<int, int>mp;

        for(int i = 0; i < n; i++) {
            int req = target - nums[i];

            if(mp.find(req) != mp.end()) {
                return {min(i, mp[req]), max(i, mp[req])};
            }

            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};
