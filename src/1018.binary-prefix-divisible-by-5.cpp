class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int acc = 0;
        vector<bool> result(A.size(), false);
        for(int i =0;i<A.size();++i){
            acc = (acc << 1) + A[i];
            if(acc % 5 == 0)
                result[i] = true;
            acc %= 5;
        }
        return result;
    }
};