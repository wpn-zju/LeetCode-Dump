class Solution {
public:
    bool isArmstrong(int N) {
        int n = N;
        vector<int> digits;
        while(N){
            digits.push_back(N % 10);
            N /= 10;
        }
        int tmp = 0;
        for(int& i : digits)
            tmp += pow(i, digits.size());
        return tmp == n;
    }
};