class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		for(int i = 1;i<triangle.size();++i)
			for (int j = 0; j < triangle[i].size(); ++j)
				if (j == 0)
					triangle[i][j] += triangle[i - 1][j];
				else if (j == triangle[i].size() - 1)
					triangle[i][j] += triangle[i - 1][j - 1];
				else
					triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
		int result = INT_MAX;
		for (int& i : triangle.back())
			result = min(result, i);
		return result;
	}
};