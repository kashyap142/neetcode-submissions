class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans;

        for (const string& s : strs) {
            ans.append(to_string(s.size()) + "#" + s);
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        const int n = s.size();

        int i = 0;

        while (i < n) {
            int j = i;
            int size = 0;

            while (s[j] != '#') {
                size = size * 10 + (s[j] - '0');
                j++;
            }

            string k = s.substr(j + 1, size);

            ans.push_back(k);

            i = j + 1 + size;
        }

        return ans;
    }
};
