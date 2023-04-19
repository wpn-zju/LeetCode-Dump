class Solution {
public:
    int rotatedDigits(int N) {
        int result = 0;
        findNumber(result, N, 0, false);
        return result;
    }
    
    void findNumber(int& result, int& bound, int cur, bool diff){
        if(cur <= bound)
            result += diff;
        else
            return;
        if(cur)
            findNumber(result, bound, cur * 10, diff);
        findNumber(result, bound, cur * 10 + 1, diff);
        findNumber(result, bound, cur * 10 + 2, true);
        findNumber(result, bound, cur * 10 + 5, true);
        findNumber(result, bound, cur * 10 + 6, true);
        findNumber(result, bound, cur * 10 + 8, diff);
        findNumber(result, bound, cur * 10 + 9, true);
    }
};