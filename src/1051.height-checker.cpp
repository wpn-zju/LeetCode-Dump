class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp = heights;
        sort(tmp.begin(), tmp.end());
        int result = 0;
        for(int i = 0;i<tmp.size();++i)
            result += heights[i] != tmp[i];
        return result;
    }
};