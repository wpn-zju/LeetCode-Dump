class Solution {
public:
	bool canReorderDoubled(vector<int>& A) {
		map<int, int> myMap;
		for (int& i : A)
			myMap[i]++;
		for (auto i = myMap.begin(); i != myMap.end(); ++i) {
            if(!i->second)
                continue;
			if (i->first < 0) {
				if (i->first % 2 || !myMap.count(i->first / 2) || myMap[i->first / 2] < i->second)
					return false;
				myMap[i->first / 2] -= i->second;
				i->second = 0;
			}
			else if (i->first == 0) {
				if (i->second % 2)
					return false;
				i->second = 0;
			}
			else {
				if (!myMap.count(i->first * 2) || myMap[i->first * 2] < i->second)
					return false;
				myMap[i->first * 2] -= i->second;
				i->second = 0;
			}
		}
		for (auto& i : myMap)
			if (i.second)
				return false;
		return true;
	}
};