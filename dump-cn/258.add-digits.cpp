class Solution {
public:
    int addDigits(int num) {
        if(num==0)
            return num;
        num %= 9;
        if(num==0)
            return 9;
        else
            return num;
    }
};