class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        const int n = nums.size();

        bool incr = true;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] < nums[i]) {
                incr = false;
                break;
            }
        }

        bool decr = true;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] > nums[i]) {
                decr = false;
                break;
            }
        }

        return incr | decr;
    }
};