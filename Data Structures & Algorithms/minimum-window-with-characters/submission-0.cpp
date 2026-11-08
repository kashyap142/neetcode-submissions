class Solution {
   private:
    bool check(const vector<int>& freq) {
        for (const int& i : freq) {
            if (i > 0) {
                return false;
            }
        }
        return true;
    }

   public:
    string minWindow(string s, string t) {
        const int n = s.size(), m = t.size();

        if (n < m) {
            return "";
        }

        vector<int> freq(128, 0);

        for (int i = 0; i < m; i++) {
            freq[t[i]]++;
            freq[s[i]]--;
        }

        freq[s[m - 1]]++;  // get rid of last removal to prevent double processing

        int l = 0, r = m - 1;

        pair<int, int> gap = {(int)1e8, -(int)1e8};

        while (r < n) {
            freq[s[r]]--;
            r++;

            while (l < n && check(freq)) {
                if (gap.first - gap.second > r - l) {
                    gap = {r, l};
                }

                freq[s[l]]++;
                l++;
            }
        }

        if (gap == make_pair((int)1e8, -(int)1e8)) {
            return "";
        }

        string ans = s.substr(gap.second, gap.first - gap.second);

        return ans;
    }
};
