class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();

        unordered_set<char>uniques(s.begin(), s.end());
        int ans = 0;

        for(const char &unique: uniques) {
            int l = 0, r = 0;

            unordered_map<char, int>mp;

            while(r < n) {
                mp[s[r]]++;

                while((r - l + 1) - mp[unique] > k) {
                    mp[s[l]]--;
                    l++;
                }

                ans = max(ans, r - l + 1);

                r++;

            }
        }

        return ans;
    }
};
