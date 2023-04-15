class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        bool neg = num < 0;
        num = abs(num);
        string result = "";
        while(num){
            result += char('0' + num % 7);
            num /= 7;
        }
        reverse(result.begin(), result.end());
        return neg ? '-' + result : result;
    }
};