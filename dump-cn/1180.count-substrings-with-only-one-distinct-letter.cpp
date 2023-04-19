class Solution {
public:
    int countLetters(string S) {
        int result = 0;
        S += 'A';
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr2 < S.size()){
            if(S[ptr2] == S[ptr1]){
                ++ptr2;
            }
            else{
                int n = ptr2 - ptr1;
                result += n * n + n >> 1;
                ptr1 = ptr2++;
            }
        }
        return result;
    }
};