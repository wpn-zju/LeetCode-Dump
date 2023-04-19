class Solution {
public:
    string toHexspeak(string num) {
        vector<char> hex{'O','I','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        uint64_t n = 0;
        for(int i =0;i<num.size();++i){
            n *= 10;
            n += num[i] - '0';
        }
        string hexa = "";
        while(n){
            if(n % 16 < 10 && n % 16 > 1)
                return "ERROR";
            hexa += hex[n % 16];
            n /= 16;
        }
        reverse(hexa.begin(), hexa.end());
        return hexa;
    }
};