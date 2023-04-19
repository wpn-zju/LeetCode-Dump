class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        set<int>prime_num = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int cnt = 0;
        for(int i=L; i<=R; i++)
        {
            bitset<32>num(i);
            if(prime_num.count(num.count()) == 1)
                cnt ++;
        }
        return cnt;
    }
};