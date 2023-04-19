class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		unordered_set<int> searchMap;
		for (int i = 0; i < arr2.size(); ++i)
			searchMap.insert(arr2[i]);
		vector<int> containers(1001, 0);
		for (int& i : arr1)
			++containers[i];
		vector<int> result;
		for (int i = 0; i < arr2.size(); ++i)
			for (int j = 0; j < containers[arr2[i]]; ++j)
				result.push_back(arr2[i]);
		for (int i = 0; i < containers.size(); ++i)
			if (!searchMap.count(i))
				for (int j = 0; j < containers[i]; ++j)
					result.push_back(i);
		return result;
	}
};