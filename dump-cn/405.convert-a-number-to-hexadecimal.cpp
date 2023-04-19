class Solution {
public:
    string dic = "0123456789abcdef";
    string toHex(int num) {
        uint32_t ui = num < 0u ? (1u << 31) + num : num;
        string output = "";
        while(ui){
            output += dic[ui & 0xf];
            ui >>= 4;
        }
        reverse(output.begin(), output.end());
        return num ? output : "0";
    }
};