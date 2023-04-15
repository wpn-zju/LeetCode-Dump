class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size())
            return false;
        for(int i =0;i<A.size();++i){
            bool tag = true;
            for(int j = 0;j<B.size();++j){
                if(B[j] != A[(j + i) % A.size()]){
                    tag = false;
                    break;
                }
            }
            if(tag)
                return true;
        }
        return A.empty();
    }
};