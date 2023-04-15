class Solution {
public:
	double getMiddle(set<int>& in) {
		vector<int> points;
		for (int i : in)
			points.push_back(i);
		if (points.size() & 1) {
			int middle = points[points.size() / 2];
			if (points.size() == 1)
				return middle;
			points.erase(find(points.begin(), points.end(), middle));
			unordered_map<double, int> countMap;
			for (int i = 0; i < points.size() / 2; ++i)
				for (int j = points.size() / 2; j < points.size(); ++j)
					++countMap[((double)points[i] + points[j]) / 2];
			for (pair<double, int> p : countMap)
				if (p.second >= points.size() / 2 && p.first == middle)
					return p.first;
		}
		else {
			unordered_map<double, int> countMap;
			for (int i = 0; i < points.size() / 2; ++i)
				for (int j = points.size() / 2; j < points.size(); ++j)
					++countMap[((double)points[i] + points[j]) / 2];
			for (pair<double, int> p : countMap)
				if (p.second >= points.size() / 2)
					return p.first;
		}
		return INT_MIN;
	}

	bool isReflected(vector<vector<int>>& points) {
		if (points.empty())
			return true;
		unordered_map<int, set<int>> pMap;
		for (vector<int>& vec : points)
			pMap[vec[1]].insert(vec[0]);
		vector<double> middle;
		for (pair<int, set<int>> p : pMap)
			middle.push_back(getMiddle(p.second));
		double same = middle[0];
		for (double& i : middle)
			if (i != same)
				return false;
		return same != INT_MIN;
	}
};