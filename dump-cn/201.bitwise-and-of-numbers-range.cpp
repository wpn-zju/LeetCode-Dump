class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 32;
        uint32_t a, b;
        while (i--){
            a = (uint32_t)m >> i << 31 >> 31;
            b = (uint32_t)n >> i << 31 >> 31;
            if (a != b)
                break;
        }
        i++;
        return (m >> i) << i;
    }
};