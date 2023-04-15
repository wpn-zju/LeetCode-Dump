class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left;i <= right;++i)
            if(isDN(i))
                result.push_back(i);
        return result;
    }
    
    bool isDN(int& n){
        int num = n * 10;
        while(num /= 10)
            if(num % 10 == 0 || n % (num % 10))
                return false;
        return true;
    }
};