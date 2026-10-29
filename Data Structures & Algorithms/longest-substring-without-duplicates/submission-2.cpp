class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        unordered_set<char>st;

        int ans = 0;

        int i = 0, j = 0;

        while(j < n) {
            if(st.find(s[j]) != st.end()) {
                while(s[i] != s[j]) {
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);

            ans = max(ans, (int)st.size());
            j++;
        }

        return ans;
    }
};
