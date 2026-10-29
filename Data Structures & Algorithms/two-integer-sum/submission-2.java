class Solution {
    public static class Pair {
        public int first;
        public int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    public int[] twoSum(int[] nums, int target) {
        final int n = nums.length;

        Pair []arr = new Pair[n];

        for(int i = 0; i < n; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        Arrays.sort(arr, Comparator.comparingInt(p -> p.first));

        int i = 0, j = n - 1;
        int [] ans = new int[2];
        while(i < j) {
            int sum = arr[i].first + arr[j].first;

            if(sum == target) {
                ans[0] = arr[i].second;
                ans[1] = arr[j].second;
                break;
            }
            else if(sum > target) {
                j--;
            }
            else {
                i++;
            }
        }

        Arrays.sort(ans);

        return ans;
    }
}