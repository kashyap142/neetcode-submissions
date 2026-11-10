class Solution {
    using ll = long long;
   private:
    ll solve(const vector<int>& arr, const int rate) {
        ll cnt = 0;

        for (const int& val : arr) {
            cnt += val / rate + (val % rate != 0);
        }
        return cnt;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();

        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int rate = l + (r - l) / 2;

            ll time = solve(piles, rate);

            if (time <= (ll)h) {
                ans = min(ans, rate);
                r = rate - 1;
            } else {
                l = rate + 1;
            }
        }

        return ans;
    }
};