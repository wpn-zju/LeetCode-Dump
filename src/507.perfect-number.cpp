class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num < 6)
            return false;
        int sqr = sqrt(num);
        int sum = sqr * sqr == num ? -sqr : 0;
        for(int i = 2;i <= sqr; ++i)
            sum += num % i == 0 ? i + num / i : 0;
        return sum + 1 == num;
    }
};