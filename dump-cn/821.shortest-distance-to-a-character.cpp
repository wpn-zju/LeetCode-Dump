class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> pos;
        for(int i = 0;i < S.size();++i)
            if(S[i] == C)
                pos.push_back(i);
        vector<int> result(S.size(), INT_MAX);
        for(int i = 0;i<S.size();++i){
            auto it = upper_bound(pos.begin(), pos.end(), i);
            if(it != pos.end())
                result[i] = *it - i;
            if(it != pos.begin())
                result[i] = min(result[i], i - *--it);
        }
        return result;
    }
};