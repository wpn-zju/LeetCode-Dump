class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4)
			return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i){
			for (int j = i + 1; j < nums.size() - 1; ++j) {
				int target_2 = target - nums[i] - nums[j];
				int start = j + 1;
				int end = nums.size() - 1;
				while (start < end) {
					if (nums[start] + nums[end] == target_2) {
						vector<int>* vecP = new vector<int>();
						vecP->push_back(nums[i]);
						vecP->push_back(nums[j]);
						vecP->push_back(nums[start]);
						vecP->push_back(nums[end]);
						result.push_back(*vecP);
						do { start++; } while (start + 1 < end && nums[start - 1] == nums[start]);
						do { end--; } while (start < end - 1 && nums[end + 1] == nums[end]);
					}
					else if (nums[start] + nums[end] < target_2)
						start++;
					else
						end--;
				}

				while (j < nums.size() - 1 && nums[j + 1] == nums[j])
					j++;
			}

			while (i < nums.size() - 1 && nums[i + 1] == nums[i])
				i++;
		}

		return result;
	}
};