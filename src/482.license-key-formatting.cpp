class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int count = 0;
        string result = "";
        for(int i = S.size() - 1;i >=0 ;--i){
            if(S[i] != '-'){
                if(S[i] >= 'a' && S[i] <= 'z')
                    S[i] += 'A' - 'a';
                result += S[i];
                if(++count % K == 0)
                    result += '-';
            }  
        }
        if(result.back() == '-')
            result.pop_back();
        reverse(result.begin(), result.end()); 
        return result;
    }
};