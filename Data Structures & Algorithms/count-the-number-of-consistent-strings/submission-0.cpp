class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>req(allowed.begin(), allowed.end());

        int ans = 0;

        for(string s : words) {
            bool ok = true;

            for(char ch: s) {
                if(req.find(ch) == req.end()) {
                    ok = false;
                }
            }

            ans += ok ? 1 : 0;
        }

        return ans;
    }
};