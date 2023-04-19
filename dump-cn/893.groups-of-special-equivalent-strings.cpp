class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        for(string& str : A){
            string s1 = "", s2 = "";
            for(int i =0;i<str.size();++i)
                if(i & 1)
                    s1 += str[i];
                else
                    s2 += str[i];
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            str = s1 + s2;
        }
        unordered_set<string> s(A.begin(), A.end());
        return s.size();
    }
};