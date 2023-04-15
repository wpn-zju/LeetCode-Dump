class Solution {
public:
    int numberOfDays(int Y, int M) {
        vector<int> m{31,28,31,30,31,30,31,31,30,31,30,31};
        if(Y % 4 == 0 && Y % 100 || Y % 400 == 0)
            return M == 2 ? 29 : m[M - 1];
        else
            return m[M - 1];
    }
};