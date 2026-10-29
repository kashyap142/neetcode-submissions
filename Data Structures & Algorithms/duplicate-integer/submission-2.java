class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> st = new HashSet<>();

        // for (int i = 0; i < nums.length; i++) {
        //     if (st.contains(nums[i])) {
        //         return true;
        //     }
        //     st.add(nums[i]);
        // }

        for(int i : nums) {
            if(st.contains(i)) {
                return true;
            }
            st.add(i);
        }

        return false;
    }
}