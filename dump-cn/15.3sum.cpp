class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			int target = -nums[i];
			int start = i + 1;
			int end = nums.size() - 1;
			while (start < end) {
				if (nums[start] + nums[end] == target) {
					vector<int>* vecP = new vector<int>();
					vecP->push_back(nums[i]);
					vecP->push_back(nums[start]);
					vecP->push_back(nums[end]);
					result.push_back(*vecP);
					do { start++; } while (start + 1 < end && nums[start - 1] == nums[start]);
					do { end--; } while (start < end - 1 && nums[end + 1] == nums[end]);
				}
				else if (nums[start] + nums[end] < target)
					start++;
				else 
					end--;
			}

			while (i < nums.size() - 1 && nums[i + 1] == nums[i])
				i++;
		}
		return result;
	}
};