class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
		for (int i = 0; i < nums.size(); ++i)
			while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				result.push_back(i + 1);
		return result;
    }
};