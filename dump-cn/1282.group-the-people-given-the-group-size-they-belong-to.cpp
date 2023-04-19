class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        
        vector<pair<int, int>> data;
        for (int i =0;i<groupSizes.size();++i)
            data.push_back({groupSizes[i], i});
        
        sort(data.begin(), data.end(), greater<pair<int, int>>());
        
        result.push_back({});
        for(int i =0;i<data.size();++i){
            result.back().push_back(data[i].second);
            if(result.back().size() == data[i].first)
                result.push_back({});
        }
        
        result.pop_back();
        
        return result;
    }
};