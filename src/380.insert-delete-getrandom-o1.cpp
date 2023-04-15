// 本题关键 O(1)删除数组中的元素 要交换后pop才行
// => getRandom()需要O(1)随机访问的容器 => 数组
// => 需要哈希表来确定值和下标的关系
// => 综上需要O(1)删除数组中的元素
class RandomizedSet {
public:
	unordered_map<int, int> data;	// val -> stamp
	vector<int> dataVec;
	/** Initialize your data structure here. */
	RandomizedSet() {
        
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (data.count(val))
			return false;
		data[val] = dataVec.size();
		dataVec.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (!data.count(val))
			return false;
		int tmp = dataVec.back();
		dataVec[dataVec.size() - 1] = val;
		dataVec[data[val]] = tmp;
		dataVec.pop_back();
		data[tmp] = data[val];
		data.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return dataVec[rand() % dataVec.size()];
	}
};