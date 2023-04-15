class Solution {
public:
	struct RSFunc {
		bool operator()(pair<char, int>*& a, pair<char, int>*& b) {
			return a->second < b->second;
		}
	};

	string reorganizeString(string S) {
		string result;
		unordered_map<char, int> countMap;
		priority_queue<pair<char, int>*, vector<pair<char, int>*>, RSFunc> myQueue;
		for (char& i : S)
			++countMap[i];
		for (auto& a : countMap)
			myQueue.push(new pair<char, int>(a));
		while (result.size() != S.size()) {
			if (result.size() == S.size() - 1)
				result.push_back(myQueue.top()->first);
			else if (myQueue.size() > 1) {
				pair<char, int>* p1 = myQueue.top();
				myQueue.pop();
				pair<char, int>* p2 = myQueue.top();
				myQueue.pop();
				result.push_back(p1->first);
				result.push_back(p2->first);
				--p1->second;
				--p2->second;
				if (p1->second)
					myQueue.push(p1);
				if (p2->second)
					myQueue.push(p2);
			}
			else
				return "";
		}
		return result;
	}
};