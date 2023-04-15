class Solution {
public:
	int largestUniqueNumber(vector<int>& A) {
		map<int, int, greater<int>> myMap;
		for (int& i : A)
			myMap[i]++;
		for (map<int, int>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
			if (iter->second == 1)
				return iter->first;
		return -1;
	}
};