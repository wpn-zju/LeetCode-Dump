class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b, carry = (int)((uint)(a & b) << 1);
        return carry == 0 ? sum : getSum(sum, carry);
    }
};