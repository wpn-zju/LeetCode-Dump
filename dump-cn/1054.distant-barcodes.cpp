class Solution {
public:
	struct RBFunc {
		bool operator()(pair<int, int>*& a, pair<int, int>*& b) {
			return a->second < b->second;
		}
	};

	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		vector<int> result;
		unordered_map<int, int> countMap;
		priority_queue<pair<int, int>*, vector<pair<int, int>*>, RBFunc> myQueue;
		for (int& i : barcodes)
			++countMap[i];
		for (auto& a : countMap)
			myQueue.push(new pair<int, int>(a));
		while (result.size() != barcodes.size()) {
			if (result.size() == barcodes.size() - 1)
				result.push_back(myQueue.top()->first);
			else {
				pair<int, int>* p1 = myQueue.top();
				myQueue.pop();
				pair<int, int>* p2 = myQueue.top();
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
		}
		return result;
	}
};