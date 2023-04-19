class Solution {
public:
    int readNumber(string& in, int& index){
        int l = 0;
        while(in[index] <= '9' && in[index] >= '0'){
            l *= 10;
            l += in[index] - '0';
            ++index;
        }
        return l;
    }
    
    bool validWordAbbreviation(string word, string abbr) {
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr2 < abbr.size()){
            if(abbr[ptr2] == '0')
                return false;
            if(abbr[ptr2] >= '0' && abbr[ptr2] <= '9')
                ptr1 += readNumber(abbr, ptr2);
            if(ptr1 > word.size())
                return false;
            if(ptr1 == word.size())
                return ptr2 == abbr.size();
            if(ptr2 >= abbr.size())
                return ptr1 == word.size();
            if(word[ptr1] != abbr[ptr2])
                return false;
            ++ptr1;
            ++ptr2;
        }
        return ptr1 == word.size();
    }
};