class Solution {
public:
	int maxDistance(vector<vector<int>>& arrays) {
		map<int, vector<int>> minMap;
		map<int, vector<int>, greater<int>> maxMap;
		for (int i = 0; i < arrays.size(); ++i) {
			minMap[arrays[i][0]].push_back(i);
			maxMap[arrays[i][arrays[i].size() - 1]].push_back(i);
		}
		auto a = minMap.begin();
		auto b = maxMap.begin();
		while (a != minMap.end() && b != maxMap.end()) {
			if (b->second.size() == 1 && a->second.size() == 1 && b->second[0] == a->second[0]) {
				auto c = a;
				auto d = b;
				++c;
				++d;
				if (b->first - c->first >= d->first - a->first) {
					a = c;
				}
				else {
					b = d;
				}
			}
			else
				return b->first - a->first;
		}
        return 0;
	}
};