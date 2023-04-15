static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
  	int str2IntOL(string& in) {
		return (in[0] - '0') * 1000 + (in[1] - '0') * 100 + (in[2] - '0') * 10 + in[3] - '0';
	}

	int openLock(vector<string>& deadends, string target) {
		unordered_set<int> dead;
		for (string& str : deadends)
			dead.insert(str2IntOL(str));
        int targetI = str2IntOL(target);
		vector<int> s(8);
		vector<int> searchMap(10000, INT_MAX);
		queue<int> myQueue;
		queue<int> len;
		myQueue.push(0);
		len.push(0);
		while (!myQueue.empty()) {
			int cur = myQueue.front();
			int curL = len.front();
			if (!dead.count(cur) && curL < searchMap[targetI] && curL < 40) {
				searchMap[cur] = min(searchMap[cur], curL);
				s[0] = cur % 10 == 9 ? cur - 9 : cur + 1;
				s[1] = cur % 10 == 0 ? cur + 9 : cur - 1;
				s[2] = (cur / 10) % 10 == 9 ? cur - 90 : cur + 10;
				s[3] = (cur / 10) % 10 == 0 ? cur + 90 : cur - 10;
				s[4] = (cur / 100) % 10 == 9 ? cur - 900 : cur + 100;
				s[5] = (cur / 100) % 10 == 0 ? cur + 900 : cur - 100;
				s[6] = (cur / 1000) % 10 == 9 ? cur - 9000 : cur + 1000;
				s[7] = (cur / 1000) % 10 == 0 ? cur + 9000 : cur - 1000;
				for(int& i : s)
					if (searchMap[i] > curL + 1) {
						myQueue.push(i);
						len.push(curL + 1);
					}
			}
            dead.insert(cur);
			myQueue.pop();
			len.pop();
		}
		return searchMap[targetI] == INT_MAX ? -1 : searchMap[targetI];
	}
};