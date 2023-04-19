class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> count(9, vector<int>(9, 0));
        for(vector<int>& vec : dominoes)
            if(vec[0] > vec[1])
                ++count[vec[1] - 1][vec[0] - 1];
            else
                ++count[vec[0] - 1][vec[1] - 1];
        int result = 0;
        for(vector<int>& vec : count)
            for(int& i : vec)
                result += i * i - i >> 1;
        return result;
    }
};