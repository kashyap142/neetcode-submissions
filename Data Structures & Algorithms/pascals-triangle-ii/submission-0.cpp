class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>>temp;

        temp.push_back({1});
        temp.push_back({1, 1});

        if(n <= 1) {
            return temp[n];
        }

        for(int i = 2; i <= n; i++) {
            vector<int>row;
            row.push_back(1);
            for(int j = 1; j < i; j++) {
                row.push_back(temp.back()[j - 1] + temp.back()[j]);
            }

            row.push_back(1);
            temp.push_back(row);
        }

        return temp.back();
    }
};