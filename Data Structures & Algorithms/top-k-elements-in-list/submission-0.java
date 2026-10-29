class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();

        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        List<Pair> arr = new ArrayList<>(mp.size());

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            arr.add(new Pair(entry.getValue(), entry.getKey()));
        }

        arr.sort(Comparator.comparingInt((Pair p) -> p.first).reversed());

        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = arr.get(i).second;
        }

        return ans;
    }

    public static class Pair {
        public int first;
        public int second;

        public Pair(int f, int s) {
            this.first = f;
            this.second = s;
        }
    }
}
