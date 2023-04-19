class Solution {
public:
	struct RSFunc {
		bool operator()(pair<char, int>*& a, pair<char, int>*& b) {
			return a->second == b->second ? a->first < b->first : a->second < b->second;
		}
	};
    
	string rearrangeString(string s, int k) {
        if(!k)
            return s;
		string result;
		unordered_map<char, int> countMap;
		priority_queue<pair<char, int>*, vector<pair<char, int>*>, RSFunc> myQueue;
		for (char& i : s)
			++countMap[i];
		for (auto& a : countMap)
			myQueue.push(new pair<char, int>(a));
		while (result.size() != s.size()) {
			if (result.size() + k > s.size()) {
				int needed = s.size() - result.size();
				if (myQueue.size() != needed)
					return "";
				while (!myQueue.empty()) {
					result.push_back(myQueue.top()->first);
					myQueue.pop();
				}
			}
			else if (myQueue.size() >= k) {
				vector<pair<char, int>*> vec;
				for (int i = 0; i < k; ++i) {
					pair<char, int>* cur = myQueue.top();
					myQueue.pop();
					vec.push_back(cur);
				}
				for (pair<char, int>*& p : vec) {
					result.push_back(p->first);
					--p->second;
					if (p->second)
						myQueue.push(p);
				}
			}
			else
				return "";
		}
		return result;
	}
};