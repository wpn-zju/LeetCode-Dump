class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        bool tag = false;
        int ptr = 2;
        for(int i = 3;i < n;++i){
            if(s[ptr] == '1'){
                if(tag)
                    s += '2';
                else
                    s += '1';
            }
            else{
                if(tag)
                    s += "22";
                else
                    s += "11";
                ++i;
            }
            tag = !tag;
            ++ptr;
        }
        int count = 0;
        for(int i = 0;i < n;++i)
            count += s[i] == '1';
        return count;
    }
};