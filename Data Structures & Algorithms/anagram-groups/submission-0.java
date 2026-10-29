class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, Integer> hm = new HashMap<>();
        List<List<String>>ans = new ArrayList<>();

        for(String str: strs) {

            // String temp = sort(str);
            char [] arr = str.toCharArray();
            Arrays.sort(arr);
            String key = new String(arr);

            if(hm.containsKey(key)) {
                ans.get(hm.get(key)).add(str);
            }
            else {
                hm.put(key, ans.size());
                List<String> list = new ArrayList<>();
                list.add(str);
                ans.add(list);
            }
        }

        return ans;
    }
}
