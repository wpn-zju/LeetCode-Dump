class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> con{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<string> strs;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr2 < S.size()){
            if(S[ptr2] != ' ')
                ++ptr2;
            else{
                strs.push_back(S.substr(ptr1, ptr2 - ptr1));
                ptr1 = ++ptr2;
            }
        }
        strs.push_back(S.substr(ptr1));
        int i = 0;
        for(string& str : strs){
            ++i;
            if(con.count(str[0]))
                str += "ma";
            else
                str = str.substr(1) + str[0] + "ma";
            for(int n = 0;n<i;++n)
                str += 'a';
        }
        S = "";
        for(string& str : strs)
            S += str + ' ';
        S.pop_back();
        return S;
    }
};