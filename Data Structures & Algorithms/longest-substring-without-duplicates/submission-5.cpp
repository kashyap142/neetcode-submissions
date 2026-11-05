class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> mp;

        while (j < n) {
            mp[s[j]]++;

            while (i < j && mp[s[j]] == 2) {
                bool toBreak = false;
                if (mp[s[i]] == 2) {  // reached at left point of repeat
                    mp[s[i]] = 1;
                    toBreak = true;
                } else {
                    mp.erase(s[i]);
                }
                i++;

                if (toBreak) {
                    break;
                }
            }
            ans = max(ans, (int)mp.size());
            j++;
        }

        return ans;
    }
};
