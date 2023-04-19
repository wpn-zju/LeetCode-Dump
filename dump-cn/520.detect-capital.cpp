class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(int i = 1;i < word.size();++i)
            count += word[i] < 'a';
        return word.front() < 'a' && count == word.size() - 1 || !count;
    }
};