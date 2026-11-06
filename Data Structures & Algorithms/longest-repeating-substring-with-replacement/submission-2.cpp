class Solution {
   public:
    int characterReplacement(string s, int k) {
        const int n = s.size();
        int l = 0, r = 0, ans = 0, maxi = 0;

        unordered_map<char, int> mp;

        while (r < n) {
            mp[s[r]]++;

            maxi = max(maxi, mp[s[r]]);

            while (l < n && (r - l + 1 - maxi) > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
