class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        unordered_map<char, int>mp;

        int ans = 0;

        int i = 0, j = 0;

        while(j < n) {
            mp[s[j]]++;

            while(i < j && mp.size() != (j - i + 1)) {
                if(mp[s[i]]-- == 1) {
                    mp.erase(s[i]);
                }
                i++;
            }
            
            ans = max(ans, (int)mp.size());

            j++;
        }

        // ans = max(ans, mp.size());

        return ans;
    }
};
