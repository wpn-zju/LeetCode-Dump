class RandomizedCollection {
public:
	unordered_map<int, unordered_set<int>> data;	// val -> stamp
	vector<int> dataVec;
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		data[val].insert(dataVec.size());
		dataVec.push_back(val);
		return data[val].size() == 1;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (!data[val].size())
			return false;        
        int cur = *(data[val].begin());
        data[val].erase(data[val].begin());
        if(cur != dataVec.size() - 1){
            dataVec[cur] = dataVec.back();
            data[dataVec.back()].erase(dataVec.size()-1);
            data[dataVec.back()].insert(cur);
        }
		dataVec.pop_back();
        return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return dataVec[rand() % dataVec.size()];
	}
};