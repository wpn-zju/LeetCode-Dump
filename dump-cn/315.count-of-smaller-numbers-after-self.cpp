
static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> output1;
	vector<int> countSmaller(vector<int>& nums) {
		output1 = vector<int>(nums.size());
		vector<pair<int, int>> vec;
		for (int i = 0; i < nums.size(); ++i)
			vec.push_back({ nums[i], i });
		mergeSort(vec, 0, nums.size() - 1);
		return output1;
	}

	void mergeSort(vector<pair<int, int>>& nums, int start, int end) {
		if (start < end) {
			int mid = (start + end) / 2;
			mergeSort(nums, start, mid);
			mergeSort(nums, mid + 1, end);
			vector<pair<int, int>> tmp;
			for (int i = start; i <= end; ++i)
				tmp.push_back(nums[i]);
			int ptr1 = start;
			int ptr2 = mid + 1;
			int ptr3 = start;
			while (ptr3 <= end) {
				if (ptr2 > end || ptr1 <= mid && tmp[ptr1 - start].first <= tmp[ptr2 - start].first) {
					nums[ptr3] = tmp[ptr1 - start];
					output1[tmp[ptr1 - start].second] += ptr2 - mid - 1;
					ptr1++;
					ptr3++;
				}
				else {
					nums[ptr3] = tmp[ptr2 - start];
					ptr2++;
					ptr3++;
				}
			}
		}
	}
};