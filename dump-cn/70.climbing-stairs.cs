public class Solution {
    public int ClimbStairs(int n) {
        int a = 1;
        int b = 1;
        for(int i =1;i<n;++i){
            a += b;
            int tmp = a;
            a = b;
            b = tmp;
        }
        return b;
    }
}