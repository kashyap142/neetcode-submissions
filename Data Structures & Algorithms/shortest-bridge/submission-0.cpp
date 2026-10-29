class Solution {
private:
    vector<pair<int, int>> solve(vector<vector<int>>&grid, vector<vector<bool>>&vis, int r, int c) {
        queue<pair<int, int>>qu;
        qu.push({r, c});
        vis[r][c] = 1;

        vector<pair<int, int>>temp;
        temp.push_back({r, c});

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        const int n = grid.size();

        while(!qu.empty()) {
            int i = qu.front().first;
            int j = qu.front().second;
            qu.pop();

            for(int k = 0; k < 4; k++) {
                int nr = i + dx[k];
                int nc = j + dy[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    qu.push({nr, nc});
                    temp.push_back({nr, nc});
                }
            }
        }

        return temp;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int n = grid.size();

        vector<vector<bool>>vis(n, vector<bool>(n, false));

        vector<vector<pair<int, int>>>islands;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    auto temp = solve(grid, vis, i, j);

                    islands.push_back(temp);
                }
            }
        }

        vector<pair<int, int>>v1 = islands[0], v2 = islands[1];

        int ans = INT_MAX;

        for(int i = 0; i < v1.size(); i++) {
            for(int j = 0; j < v2.size(); j++) {
                int diff = abs(v1[i].first - v2[j].first) + abs(v1[i].second - v2[j].second);

                ans = min(ans, diff - 1);
            }
        }

        return ans;
    }
};

/*
0, 1

2, 2

*/