class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		int sum = 0;
		for (int& i : A)
			if (!(i & 1))
				sum += i;
		vector<int> result;
		for (int i = 0; i < queries.size(); ++i) {
			if (!(A[queries[i][1]] & 1))
				sum -= A[queries[i][1]];
			A[queries[i][1]] += queries[i][0];
			if (!(A[queries[i][1]] & 1))
				sum += A[queries[i][1]];
            result.push_back(sum);
		}
		return result;
	}
};