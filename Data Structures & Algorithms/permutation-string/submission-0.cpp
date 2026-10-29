class Solution {
   private:
    bool check(const int arr[]) {
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }

        return true;
    }

   public:
    bool checkInclusion(string s1, string s2) {
        const int m = s1.size(), n = s2.size();

        if (m > n) {
            return false;
        }

        int arr[26] = {0};

        for (int i = 0; i < m; i++) {
            arr[s1[i] - 'a']++;
            arr[s2[i] - 'a']--;
        }

        // reset the last decresement so that we can start
        // the next loop at that point
        arr[s2[m - 1] - 'a']++;

        for (int i = m - 1; i < n; i++) {
            arr[s2[i] - 'a']--;

            if (check(arr)) {
                return true;
            }
            arr[s2[i - m + 1] - 'a']++;
        }

        return false;
    }
};
