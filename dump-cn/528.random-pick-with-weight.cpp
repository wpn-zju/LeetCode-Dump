class Solution {
public:
	vector<int>* data;
	Solution(vector<int>& w) {
		data = new vector<int>(w.size());
		int sum = 0;
		for (int i = 0; i < w.size(); ++i)
			(*data)[i] = (sum += w[i]);
	}

	int pickIndex() {
		int r = rand() % data->back();
		int start = 0;
		int end = data->size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if ((*data)[mid] <= r)
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}
};