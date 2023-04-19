class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        vector<int> count(26, 0);
        int dismatched = -1;
        bool tag = false;
        for(int i =0;i<A.size();++i){
            ++count[A[i] - 'a'];
            if(A[i] != B[i]){
                if(tag)
                    return false;
                if(dismatched == -1)
                    dismatched = i;
                else{
                    if(A[dismatched] == B[i] && A[i] == B[dismatched])
                        tag = true;
                    else
                        return false;
                }
            }
        }
        if(tag)
            return true;
        if(dismatched != -1)
            return false;
        for(int i = 0;i<26;++i)
            if(count[i] >= 2)
                return true;
        return false;
    }
};