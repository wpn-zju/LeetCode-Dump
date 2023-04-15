class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> result;
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr1 < A.size() && ptr2 < B.size()) {
			if (A[ptr1][0] >= B[ptr2][0]) {
				if (A[ptr1][0] <= B[ptr2][1])
					if (result.size() != 0 && result.back()[1] >= A[ptr1][0])
						result.back()[1] = min(result.back()[1], A[ptr1][1]);
					else
						result.push_back(vector<int>{A[ptr1][0], min(A[ptr1][1], B[ptr2][1])});
			}
			else {
				if (B[ptr2][0] <= A[ptr1][1])
					if (result.size() != 0 && result.back()[1] >= B[ptr2][0])
						result.back()[1] = min(result.back()[1], B[ptr2][1]);
					else
						result.push_back(vector<int>{B[ptr2][0], min(A[ptr1][1], B[ptr2][1])});
			}
			if (A[ptr1][1] >= B[ptr2][1])
				ptr2++;
			else
				ptr1++;
		}
		return result;
	}
};