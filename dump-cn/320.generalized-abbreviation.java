class Solution {
    
    public List<String> generateAbbreviations(String word) {
        List<String> ans = new ArrayList<>();
        char[] chars = word.toCharArray();
        int n = word.length();
        int all = 1 << n;
        for (int i = 0; i < all; i++) {
            StringBuilder builder = new StringBuilder();
            int count = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    builder.append(count == 0 ? "" : count).append(chars[j]);
                    count = 0;
                } else {
                    count++;
                }
            }
            if (count > 0) builder.append(count);
            ans.add(builder.toString());
        }
        return ans;
    }
}