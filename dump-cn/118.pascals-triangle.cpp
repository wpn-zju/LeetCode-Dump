class Solution {
public:
	vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return {};
        if(numRows == 1)
            return {{1}};
		vector<vector<int>> result{ {1},{1,1} };
		for (int i = 3; i <= numRows; ++i) {
			vector<int> tmp{ 1 };
			for (int j = 0; j < result.back().size() - 1; ++j)
				tmp.push_back(result.back()[j] + result.back()[j + 1]);
			tmp.push_back(1);
			result.push_back(tmp);
		}
		return result;
	}
};