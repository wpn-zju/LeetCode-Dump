class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(vector<int>& vec : A)
            reverse(vec.begin(), vec.end());
        for(vector<int>& vec : A)
            for(int& i : vec)
                i = !i;
        return A;
    }
};