class Solution {
public:
	int subarraysWithKDistinct(vector<int>& A, int K) {
		int m = A.size();
		unordered_map<int, int> map;
		int ptr1 = 0;
		int ptr2 = 0;
		int count = 0;
		int result = 1;
		int results = 0;
		while (ptr2 < m) {
			map[A[ptr2]]++;
			if (map[A[ptr2]] == 1)
				count++;

			while (map[A[ptr1]] > 1 || count > K) {
				if (count > K) {
					result = 1;
					count--;
				}
				else
					result++;
				map[A[ptr1]]--;
				ptr1++;
			}

			if (count == K)
				results += result;
            ptr2++;
		}
		return results;
	}
};