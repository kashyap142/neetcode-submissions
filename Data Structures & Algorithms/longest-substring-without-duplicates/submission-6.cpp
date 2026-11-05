class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        unordered_set<char> st;

        int left = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            while (st.find(s[i]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[i]);
            ans = max(ans, (int)st.size());
        }

        return ans;
    }
};
