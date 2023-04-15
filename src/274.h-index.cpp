class Solution {
public:
	int hIndex(vector<int>& citations) {
		vector<int> cMap(citations.size() + 1);
		for (int& i : citations)
			if (i > citations.size())
				cMap[citations.size()]++;
			else
				cMap[i]++;
		int count = 0;
		for (int i = citations.size(); i >= 0; --i)
			if ((count += cMap[i]) >= i)
				return i;
		return 0;
	}
};