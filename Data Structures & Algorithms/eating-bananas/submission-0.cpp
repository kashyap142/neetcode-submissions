class Solution {
    using ll = long long;

private:
    int solve(const vector<int>&arr, const int rate) {
        const int n = arr.size();

        int cnt = 0;

        for(const auto &v: arr) {
            cnt += (v + rate - 1) / rate;
        }

        return cnt;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();

        int mini = 1, maxi = *max_element(piles.begin(), piles.end());
        int ans = maxi;

        while (mini <= maxi) {
            int mid = (mini + maxi) / 2;

            auto time = solve(piles, mid);

            if(time <= h) {
                ans = mid;
                maxi = mid - 1;
            }
            else {
                mini = mid + 1;
            }
        }

        return ans;
    }
};
