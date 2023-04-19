static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int result = 0;
		vector<int> tmp(nums.size());
		mergeSort(nums, tmp, 0, nums.size() - 1, result);
		return result;
	}

	void mergeSort(vector<int>& nums, vector<int>& tmp, int start, int end, int& result) {
		if (start < end) {
			int mid = (start + end) / 2;
			mergeSort(nums, tmp, start, mid, result);
			mergeSort(nums, tmp, mid + 1, end, result);
			for (int i = start; i <= end; ++i)
				tmp[i - start] = nums[i];
			int ptr1 = start;
			int ptr2 = mid + 1;
			int ptr3 = start;
			int ptr4 = mid + 1;
			while (ptr3 <= end) {
				if (ptr2 > end || ptr1 <= mid && tmp[ptr1 - start] <= tmp[ptr2 - start]) {
					nums[ptr3++] = tmp[ptr1 - start];
					while (ptr4 <= end && (int64_t)tmp[ptr1 - start] > (int64_t)tmp[ptr4 - start] * 2)
						++ptr4;
					result += ptr4 - mid - 1;
					ptr1++;
				}
				else
					nums[ptr3++] = tmp[ptr2++ - start];
			}
		}
	}
};