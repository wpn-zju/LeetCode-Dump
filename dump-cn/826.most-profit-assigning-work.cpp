class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		int m = difficulty.size();
		int n = worker.size();
		vector<pair<int, int>> data;
		for (int i = 0; i < m; ++i)
			data.push_back(pair<int, int>(profit[i], difficulty[i]));
		sort(data.begin(), data.end());
		sort(worker.begin(), worker.end());	
		int maxProfit = 0;
		int ptr1 = m - 1;
		int ptr2 = n - 1;
		while (ptr2 >= 0) {
			while (ptr1 >= 0 && data[ptr1].second > worker[ptr2])
				ptr1--;
            if(ptr1 >= 0)
			    maxProfit += data[ptr1].first;
			ptr2--;
		}
		return maxProfit;
	}
};