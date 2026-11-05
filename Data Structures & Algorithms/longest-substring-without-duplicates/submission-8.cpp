class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        unordered_map<char, int> mp;  // char, last index

        int ans = 0, left = 0;

        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                left = max(left, mp[s[i]] + 1);
            }

            mp[s[i]] = i;
            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};
