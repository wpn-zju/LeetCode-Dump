class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (nums.empty())
			return false;
		uint32_t sum = 0;
		unordered_map<int, int> visited;
		for (int& i : nums) {
			sum += i;
			++visited[i];
		}
		if (sum % 4)
			return false;
		int edge = sum / 4;
		vector<int> after;
		for (pair<int, int> p : visited)
			after.push_back(p.first);
		sort(after.begin(), after.end(), greater<int>());
		bool result = false;
		--visited[after[0]];
		dfsMakeSquare(result, after, visited, after[0], 4, edge);
		++visited[after[0]];
		return result;
	}

	void dfsMakeSquare(bool& result, vector<int>& nums, unordered_map<int, int>& visited, int cur, int num, int& target) {
		if (result)
			return;
		if (cur == target) {
			if (--num == 0) {
				result = true;
				return;
			}
			else
				cur = 0;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[nums[i]] && cur + nums[i] <= target) {
				--visited[nums[i]];
				dfsMakeSquare(result, nums, visited, cur + nums[i], num, target);
				++visited[nums[i]];
			}
		}
	}
};