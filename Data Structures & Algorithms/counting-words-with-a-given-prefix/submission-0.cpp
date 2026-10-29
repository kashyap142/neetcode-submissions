class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(string s : words) {
            if(s.size() >= pref.size()) {
                bool ok = true;
                for(int i = 0; i < pref.size(); i++) {
                    if(pref[i] != s[i]) {
                        ok = false;
                        break;
                    }
                }

                ans += ok ? 1 : 0;
            }
        }

        return ans;
    } 
};