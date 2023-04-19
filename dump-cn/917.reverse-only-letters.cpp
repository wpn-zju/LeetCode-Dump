class Solution {
public:
    bool isLetter(char c){
        return c >= 'a' && c<= 'z' || c>='A' && c<='Z';
    }
    
    string reverseOnlyLetters(string S) {
        string T = S;
        int ptr = T.size() - 1;
        for(int i =0 ;i<S.size();++i){
            if(isLetter(S[i])){
                while(!isLetter(T[ptr]))
                    --ptr;
                S[i] = T[ptr];
                --ptr;
            }
        }
        return S;
    }
};