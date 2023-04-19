class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> count(26, 0);
		for (int i = 0; i < tasks.size(); ++i)
			count[tasks[i] - 'A']++;
		sort(count.begin(), count.end());
		int maxCount = 0;
		for (int i = 25; i >= 0; --i){
			if (count[i] != count[25])
				break;            
            maxCount++;
        }
		return max((count[25] - 1)*(n + 1) + maxCount, (int)tasks.size());
	}
};