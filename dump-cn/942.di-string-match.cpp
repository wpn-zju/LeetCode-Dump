class Solution {
public:
    vector<int> diStringMatch(string S) {
        S += 'I';
        vector<int> result(S.size());
        for(int i =0;i<result.size();++i)
            result[i] = i;
        int curL = 0;
        for(int i = 0;i<S.size();++i){
            if(S[i] == 'D')
                ++curL;
            else if(curL){
                reverse(result.begin() + i - curL, result.begin() + i + 1);
                curL = 0;
            }
        }
        return result;
    }
};