static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> result;
		int cur1 = 0;
		int cur2 = 0;
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if ((count1 == 0 || nums[i] == cur1) && nums[i] != cur2) {
				++count1;
				cur1 = nums[i];
			}
			else if (count2 == 0 || nums[i] == cur2) {
				++count2;
				cur2 = nums[i];
			}
			else {
				--count1;
				--count2;
			}
		}
		count1 = count2 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == cur1)
				++count1;
			if (nums[i] == cur2)
				++count2;
		}
		if (count1 > nums.size() / 3)
			result.push_back(cur1);
		if (cur2 != cur1 && count2 > nums.size() / 3)
			result.push_back(cur2);
		return result;
	}
};