class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans("");

        for (const string& str : strs) {
            ans.append("#" + to_string(str.size()) + "#" + str);
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        const uint n = s.size();

        uint i = 0;
        while (i < n) {
            // size "#size#"
            // move size index next, repeat

            int size = 0;
            i++;                            // since s[i] will be hash, start of size identifer
            while (i < n && s[i] != '#') {  // till end of size identifer
                size = size * 10 + (s[i] - '0');
                i++;
            }

            ans.push_back(s.substr(i + 1, size));

            i += size + 1;
        }

        return ans;
    }
};
