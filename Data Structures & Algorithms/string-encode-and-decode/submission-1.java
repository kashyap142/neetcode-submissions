class Solution {

    public String encode(List<String> strs) {
        StringBuilder ans = new StringBuilder();

        for(String str: strs) {
            ans.append("#")
                .append(str.length())
                .append("#")
                .append(str);
        }

        return ans.toString();
    }

    public List<String> decode(String str) {
        List<String>ans = new ArrayList<>();

        final int n = str.length();
        int i = 0;
        while(i < n) {
            int size = 0;
            i++;

            while(i < n && str.charAt(i) != '#') {
                size = size * 10 + str.charAt(i) - '0';
                i++;
            }

            ans.add(str.substring(i + 1, i + size + 1));

            i += size + 1;
        }

        return ans;
    }
}
