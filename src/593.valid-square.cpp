class Solution {
public:
    int getLength(vector<int>& p1, vector<int>& p2) {
		return (p2[0] - p1[0])*(p2[0] - p1[0])+(p2[1] - p1[1])*(p2[1] - p1[1]);
	}
    
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		unordered_map<int, int> lMap;
		lMap[getLength(p1, p2)]++;
		lMap[getLength(p1, p3)]++;
		lMap[getLength(p1, p4)]++;
		lMap[getLength(p2, p3)]++;
		lMap[getLength(p2, p4)]++;
		lMap[getLength(p3, p4)]++;
		if (lMap.size() != 2)
			return false;
		auto iter = lMap.begin();
		int l1 = iter->first;
		int l2 = (++iter)->first;
		if (lMap[l1] == 4 && lMap[l2] == 2)
			return l2 = 2 * l1;
		else if (lMap[l1] == 2 && lMap[l2] == 4)
			return l1 = 2 * l2;
		else
			return false;
	}
};