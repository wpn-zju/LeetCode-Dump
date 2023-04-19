class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
        for(char& c : text)
            ++count[c - 'a'];
        return min(count['b' - 'a'], min(count['a' - 'a'], min(count['l' - 'a'] >> 1, min(count['o' - 'a'] >> 1, count['n' - 'a']))));
    }
};