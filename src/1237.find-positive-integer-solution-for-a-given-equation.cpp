class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        int x = 1, y = 1000;
        while(x <= 1000 && y >= 1){
            int get = customfunction.f(x, y);
            if(get == z)
                result.push_back({x++, y--});
            else if(get < z)
                ++x;
            else
                --y;
        }
        return result;
    }
};