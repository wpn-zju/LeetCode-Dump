class Solution {
public:
	int findLHS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
		map<int, int> myMap;
		for (int i = 0; i < nums.size(); ++i)
			myMap[nums[i]]++;
		int result = 0;
		auto a = myMap.begin();
		auto b = myMap.begin();
		++b;
		while (b != myMap.end()) {
			if (b->first - a->first == 1)
				result = max(result, a->second + b->second);
			++b;
			++a;
		}
		return result;
	}
};