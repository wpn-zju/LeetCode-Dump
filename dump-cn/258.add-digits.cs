public class Solution {
    public int AddDigits(int num) {
        if(num == 0) return 0;
        return (num %= 9) == 0 ? 9 : num;
    }
}