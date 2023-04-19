class TwoSum {
public:
	unordered_map<int, int> numMap;
	/** Initialize your data structure here. */
	TwoSum() {

	}

	/** Add the number to an internal data structure.. */
	void add(int number) {
		numMap[number]++;
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) {
		for (pair<int, int> kvp : numMap) {
			if (2 * kvp.first == value && kvp.second > 1)
				return true;
			if (2 * kvp.first != value && numMap.count(value - kvp.first))
				return true;
		}
		return false;
	}
};