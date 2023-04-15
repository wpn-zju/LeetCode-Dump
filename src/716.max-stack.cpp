class MaxStack {
public:
	int timeStamp;
	map<int, int> data;
	map<int, vector<int>, greater<int>> myMap;
	/** initialize your data structure here. */
	MaxStack() {
		timeStamp = 0;
	}

	void push(int x) {
		data[timeStamp] = x;
		if (myMap.count(x))
			myMap[x].push_back(timeStamp);
		else
			myMap[x] = vector<int>{ timeStamp };
		timeStamp++;
	}

	int pop() {
        map<int, int>::iterator iter = data.end();
        iter--;
		int result = iter->second;
		data.erase(iter);
		myMap[result].pop_back();
		if (myMap[result].size() == 0)
			myMap.erase(result);
		return result;
	}

	int top() {
		map<int, int>::iterator iter = data.end();
		iter--;
		return iter->second;
	}

	int peekMax() {
		return myMap.begin()->first;
	}

	int popMax() {
		int result = myMap.begin()->first;
		data.erase(myMap.begin()->second.back());
		myMap.begin()->second.pop_back();
		if (myMap.begin()->second.size() == 0)
			myMap.erase(myMap.begin());
		return result;
	}
};