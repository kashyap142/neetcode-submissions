class Solution {
private:
    using pii = pair<int, int>;
    using vvi = vector<vector<int>>;
    int m, n;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    void bfs(const vvi &grid, vvi &vis, int x, int y) {
        vis[x][y] = 0; // bad at t = 0
        queue<vector<int>>qu;
        qu.push({x, y, 0}); // x, y, time

        while(!qu.empty()) {
            int r = qu.front()[0], c = qu.front()[1], t = qu.front()[2];
            qu.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(grid[nr][nc] == 1) {
                        if((t + 1) < vis[nr][nc]) {
                            vis[nr][nc] = t + 1;
                            qu.push({nr, nc, t + 1});
                        }
                    }
                }
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid.front().size();

        // stores the min time it takes to trun bad (if applicable)
        vector<vector<int>>vis(m, vector<int>(n, INT_MAX));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    bfs(grid, vis, i, j);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && vis[i][j] == INT_MAX) {
                    return -1;
                }

                if(grid[i][j] == 1) {
                    ans = max(ans, vis[i][j]);
                }
                
            }
        }

        return ans;
    }
};
