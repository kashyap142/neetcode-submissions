class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (const int& val : nums) {
            if (st.find(val - 1) == st.end()) {  // possible start of sequence

                int cnt = 1, k = val + 1;
                while (st.find(k) != st.end()) {  // keep looking until seq ends
                    cnt++;
                    k++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
