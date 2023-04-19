class Solution {
public:
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
		vector<int> result(max(arr1.size(), arr2.size()) + 5, 0);
		reverse(arr1.begin(), arr1.end());
		reverse(arr2.begin(), arr2.end());
		int ptr1 = 0, ptr2 = 0, ptr3 = 0;
		while (ptr1 < arr1.size() || ptr2 < arr2.size())
			result[ptr3++] += (ptr1 < arr1.size() ? arr1[ptr1++] : 0) + (ptr2 < arr2.size() ? arr2[ptr2++] : 0);
		for (int i = 0; i < result.size() - 1; ++i) {
			if (result[i] > 1)
				result[i + 1] -= result[i] >> 1;
			else if (result[i] < 0)
				result[i + 1] += (-result[i] >> 1) + 1;
			result[i] &= 1;
		}
		while (!result.back() && result.size() > 1)
			result.pop_back();
		reverse(result.begin(), result.end());
		return result;
	}
};