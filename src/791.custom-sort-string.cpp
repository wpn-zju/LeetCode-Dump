class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> m(26, 26);
        for(int i =0;i<S.size();++i)
            m[S[i]-'a'] = i;
        sort(T.begin(), T.end(), [m](char& a, char& b){return m[a-'a'] < m[b-'a'];});
        return T;
    }
};