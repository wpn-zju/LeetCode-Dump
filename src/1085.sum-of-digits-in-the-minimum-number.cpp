class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int mn = INT_MAX;
        for(int& i : A)
            mn = min(i, mn);
        int result = 0;
        while(mn){
            result += mn % 10;
            mn /= 10;
        }
        return !(result & 1);
    }
};