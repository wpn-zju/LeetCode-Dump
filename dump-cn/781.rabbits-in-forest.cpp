class Solution {
public:
	int numRabbits(vector<int>& answers) {
		int count = 0;
		unordered_map<int, int> colorMap;
		for (int& i : answers) {
			if (colorMap.count(i) && colorMap[i])
				colorMap[i]--;
			else {
				colorMap[i] = i;
				count += i + 1;
			}
		}
		return count;
	}
};