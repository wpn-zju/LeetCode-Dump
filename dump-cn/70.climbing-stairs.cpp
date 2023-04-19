class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        for(int i =1;i<n;++i){
            a += b;
            swap(a, b);
        }
        return b;
    }
};