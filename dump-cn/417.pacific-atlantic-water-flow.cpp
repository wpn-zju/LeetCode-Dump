static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> result;
		if (!matrix.size())
			return result;
		queue<pair<int, int>> myQueue;
		vector<vector<bool>> tag1(matrix.size(), vector<bool>(matrix[0].size(), false));
		vector<vector<bool>> tag2(matrix.size(), vector<bool>(matrix[0].size(), false));
		for (int i = 0; i < matrix.size(); ++i)
			myQueue.push({ i,0 });
		for (int i = 1; i < matrix[0].size(); ++i)
			myQueue.push({ 0,i });
		while (!myQueue.empty()) {
			pair<int, int>& cur = myQueue.front();
			int i = cur.first;
			int j = cur.second;
			tag1[i][j] = true;
			if (i != 0 && matrix[i - 1][j] >= matrix[i][j] && !tag1[i - 1][j])
				myQueue.push({ i - 1,j });
			if (j != 0 && matrix[i][j - 1] >= matrix[i][j] && !tag1[i][j - 1])
				myQueue.push({ i,j - 1 });
			if (i != matrix.size() - 1 && matrix[i + 1][j] >= matrix[i][j] && !tag1[i + 1][j])
				myQueue.push({ i + 1,j });
			if (j != matrix[0].size() - 1 && matrix[i][j + 1] >= matrix[i][j] && !tag1[i][j + 1])
				myQueue.push({ i,j + 1 });
			myQueue.pop();
		}
		queue<pair<int, int>>().swap(myQueue);
		for (int i = 0; i < matrix.size(); ++i)
			myQueue.push({ i,matrix[0].size() - 1 });
		for (int i = 0; i < matrix[0].size() - 1; ++i)
			myQueue.push({ matrix.size() - 1,i });
		while (!myQueue.empty()) {
			pair<int, int>& cur = myQueue.front();
			int i = cur.first;
			int j = cur.second;
			tag2[i][j] = true;
			if (i != 0 && matrix[i - 1][j] >= matrix[i][j] && !tag2[i - 1][j])
				myQueue.push({ i - 1,j });
			if (j != 0 && matrix[i][j - 1] >= matrix[i][j] && !tag2[i][j - 1])
				myQueue.push({ i,j - 1 });
			if (i != matrix.size() - 1 && matrix[i + 1][j] >= matrix[i][j] && !tag2[i + 1][j])
				myQueue.push({ i + 1,j });
			if (j != matrix[0].size() - 1 && matrix[i][j + 1] >= matrix[i][j] && !tag2[i][j + 1])
				myQueue.push({ i,j + 1 });
			myQueue.pop();
		}
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
				if (tag1[i][j] && tag2[i][j])
					result.push_back({ i,j });
		return result;
	}
};