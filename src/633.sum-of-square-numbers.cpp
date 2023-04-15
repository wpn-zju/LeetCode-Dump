class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c); ++i){
            int n = c - i * i;
            int t = sqrt(n);
            if(t * t == n)
                return true;
        }
        return false;
    }
};