class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> count(2001, 0);
        for(int& i : arr)
            ++count[i + 1000];
        unordered_set<int> s;
        for(int& i : count)
            if(i)
                if(s.count(i))
                    return false;
                else
                    s.insert(i);
        return true;
    }
};