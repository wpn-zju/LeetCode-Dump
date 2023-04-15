class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> worddic(wordList.begin(),wordList.end());
        unordered_set<string> beginset={beginWord};
        unordered_set<string> endset={endWord};
        if(worddic.count(endWord)==0)
            return 0;
        int res=1;
        for(;!beginset.empty();){
            res++;
            unordered_set<string> tmpset;
            for(auto s:beginset)
                worddic.erase(s);
            for(string s:beginset){
                for(int i=s.size()-1;i>=0;i--){
                    string str=s;
                    for(char c='a';c<='z';c++){
                        str[i]=c;
                        if(worddic.count(str)==0)
                            continue;
                        if(endset.count(str)==1)
                            return res;
                        tmpset.insert(str);
                    }
                }
            }
            if(tmpset.size()<endset.size())
                beginset=tmpset;
            else{
                beginset=endset;
                endset=tmpset;
            }
        }
        return 0;
    }
};