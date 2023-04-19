class Solution {
public:
    int clumsy(int N) {
        vector<int> t{0,1,2,6};
        if(N < 4)
            return t[N];
        int result = N * (N - 1) / (N - 2) + (N - 3);
        int n = N - 4;
        while(n >= 4){
            result -= n * (n - 1) / (n - 2);
            result += (n - 3);
            n -= 4;
        }
        return result - t[n];
    }
};