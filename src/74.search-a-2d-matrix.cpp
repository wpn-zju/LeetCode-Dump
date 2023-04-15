static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		int start = 0;
		int end = matrix.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (matrix[mid][0] < target)
				start = mid + 1;
			else
				end = mid;
		}
		int tmp = matrix[start][0] > target ? start - 1 : start;
		if (tmp < 0)
			return false;
		start = 0;
		end = matrix[0].size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (matrix[tmp][mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		return matrix[tmp][start] == target;
	}
};