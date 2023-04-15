class Solution {
public:
    int bitwiseComplement(int N) {
        return N ? (1 << 1 + (int)log2(N)) - 1 - N : 1;
    }
};