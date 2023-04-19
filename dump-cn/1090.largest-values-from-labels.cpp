class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		vector<vector<int>> labelVec;
		for (int i = 0; i < values.size(); ++i) {
			vector<int> vec;
			vec.push_back(labels[i]);
			vec.push_back(values[i]);
			labelVec.push_back(vec);
		}
		sort(labelVec.begin(), labelVec.end(), [](vector<int>& a, vector<int>& b) {return a[1] > b[1]; });
		unordered_map<int, int> labelMap;
		int ptr = 0;
		int count = 0;
		int sum = 0;
		while (ptr < labelVec.size() && count < num_wanted) {
			if (labelMap[labelVec[ptr][0]]++ < use_limit) {
				count++;
				sum += labelVec[ptr][1];
			}
			ptr++;
		}
		return sum;
	}
};