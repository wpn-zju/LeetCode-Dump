class Solution {
public:
	vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
		vector<int> result;
		int ptr1 = 0, ptr2 = 0, ptr3 = 0;
		while (ptr1 < arr1.size() && ptr2 < arr2.size() && ptr3 < arr3.size()) {
			if (arr1[ptr1] == arr2[ptr2] && arr1[ptr1] == arr3[ptr3]) {
				result.push_back(arr1[ptr1]);
				++ptr1;
				++ptr2;
				++ptr3;
			}
			else {
				int t = min(arr1[ptr1], min(arr2[ptr2], arr3[ptr3]));
				ptr1 += t == arr1[ptr1];
				ptr2 += t == arr2[ptr2];
				ptr3 += t == arr3[ptr3];
			}
		}
		return result;
	}
};