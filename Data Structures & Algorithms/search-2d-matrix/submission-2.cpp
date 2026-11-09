class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix.front().size();

        int l = 0, r = m * n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            int x = mid / n, y = mid % n;

            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};
