class Solution {
public:
    int numSquares(int n) {
        while (0 == n % 4) n /= 4;
        if (7 == n % 8) return 4;
        for (int i = 0; i * i < n; ++i) {
            int j = sqrt(n - i * i);
            if (n == i * i + j * j) return !!i + !!j;
        }
        return 3;
    }
};