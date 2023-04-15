class Solution {
public:
    bool prime(int n){
        for(int i = 2;i < n;++i)
            if(n % i == 0)
                return false;
        return true;
    }
    
    int64_t permu(int n){
        int64_t result = 1;
        while(n){
            result *= n;
            result %= 1000000007;
            --n;
        }
        return result;
    }
    
    int numPrimeArrangements(int n) {
        int count = 0;
        for(int i = 2;i<=n;++i)
            count += prime(i);
        return permu(count) * permu(n - count) % 1000000007;
    }
};