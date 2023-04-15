static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		vector<int> vec1{ 1 };
		vector<int> vec2{ 1 };
		if (x != 1)
			while (vec1.back()*x < bound)
				vec1.push_back(vec1.back()*x);
		if (y != 1)
			while (vec2.back()*y < bound)
				vec2.push_back(vec2.back()*y);
		unordered_set<int> mySet;
		for (int i = 0; i < vec1.size(); ++i)
			for (int j = 0; j < vec2.size(); ++j)
				if (vec1[i] + vec2[j] <= bound)
					mySet.insert(vec1[i] + vec2[j]);
		vector<int> result;
		for (auto& a : mySet)
			result.push_back(a);
		return result;
	}
};