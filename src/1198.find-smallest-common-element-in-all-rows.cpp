static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool bSearch(vector<int>& vec, int& target) {
		int start = 0;
		int end = vec.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (vec[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		return vec[start] == target;
	}

	int smallestCommonElement(vector<vector<int>>& mat) {
		if (mat.empty())
			return -1;
		for (int i = 0; i < mat[0].size(); ++i) {
			bool flag = true;
			for (int j = 1; j < mat.size(); ++j)
				if (!bSearch(mat[j], mat[0][i])) {
					flag = false;
					break;
				}
			if (flag)
				return mat[0][i];
		}
		return -1;
	}
};