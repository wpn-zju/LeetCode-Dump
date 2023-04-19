class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int div = B.size() / A.size() + 1;
        string t = A;
        for(int i =0;i<div;++i)
            t += A;
        int it = t.find(B);
        if(it == string::npos)
            return -1;
        return ceil(((double)it + B.size()) / A.size());
    }
};