class Solution {
   public:
    int characterReplacement(string s, int k) {
        const int n = s.size();

        unordered_map<char, int> mp;

        int ans = 0, maxF = 0;
        int l = 0, r = 0;

        while (r < n) {
            mp[s[r]]++;
            maxF = max(maxF, mp[s[r]]);

            while ((r - l + 1) - maxF > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
