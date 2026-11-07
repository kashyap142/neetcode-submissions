class Solution {
   private:
    bool check(const vector<int>& cnt, const vector<int>& sub) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != sub[i]) return false;
        }
        return true;
    }

   public:
    bool checkInclusion(string s1, string s2) {
        const int n = s1.size(), m = s2.size();

        if (n > m) {  // s1 big, s2 smol
            return false;
        }

        vector<int> cnt(26);
        for (const char& ch : s1) {
            cnt[ch - 'a']++;
        }

        int l = 0, r = 0;
        vector<int> sub(26);

        while (r < n - 1) {  // first n - 1 character
            sub[s2[r] - 'a']++;
            r++;
        }

        while (r < m) {
            sub[s2[r] - 'a']++;

            if (check(cnt, sub)) {
                return true;
            }

            sub[s2[l] - 'a']--;
            r++, l++;
        }

        return false;
    }
};
