class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        size_t n = strs.size();

        vector<vector<string>> ans;
        unordered_map<string, int> mp;

        for (const string& str : strs) {
            string s = str;
            sort(s.begin(), s.end());

            if (mp.find(s) != mp.end()) {
                ans[mp[s]].push_back(str);
            } else {
                mp[s] = ans.size();
                ans.push_back({str});
            }
        }

        return ans;
    }
};
