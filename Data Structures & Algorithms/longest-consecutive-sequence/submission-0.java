class Solution {
    public int longestConsecutive(int[] nums) {
        TreeSet<Integer> st = new TreeSet<>();

        for (int num : nums) {
            st.add(num);
        }

        int last = Integer.MIN_VALUE;
        int ans = 0, cnt = 0;

        for (int val : st) {
            if (val - last == 1) {
                cnt++;
            } else {
                ans = Math.max(ans, cnt);
                cnt = 1;
            }

            last = val;
        }

        ans = Math.max(ans, cnt);

        return ans;
    }
}
