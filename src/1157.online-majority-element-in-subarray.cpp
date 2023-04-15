	class SegmentModeNode {
	public:
		int val;
		int count;
		int start;
		int end;
		SegmentModeNode* left;
		SegmentModeNode* right;

		SegmentModeNode(int start, int end) {
			this->start = start;
			this->end = end;
			this->left = this->right = nullptr;
		}
	};

	class SegmentModeTree {
	public:
		SegmentModeNode* head;

		SegmentModeTree(vector<int>& input) {
			head = buildTree(input, 0, input.size() - 1);
		}

		SegmentModeNode* buildTree(vector<int>& input, int start, int end) {
			SegmentModeNode* newNode = new SegmentModeNode(start, end);
			if (start == end) {
				newNode->count = 1;
				newNode->val = input[start];
				return newNode;
			}

			int mid = start + (end - start >> 1);
			newNode->left = buildTree(input, start, mid);
			newNode->right = buildTree(input, mid + 1, end);

			if (newNode->left->val == newNode->right->val) {
				newNode->count = newNode->left->count + newNode->right->count;
				newNode->val = newNode->left->val;
			}
			else if (newNode->left->count <= newNode->right->count) {
				newNode->count = newNode->right->count - newNode->left->count;
				newNode->val = newNode->right->val;
			}
			else {
				newNode->count = newNode->left->count - newNode->right->count;
				newNode->val = newNode->left->val;
			}

			return newNode;
		}

		pair<int, int> search(SegmentModeNode* cur, int start, int end) {
			if (cur->start == start && cur->end == end)
				return { cur->val, cur->count };
			pair<int, int> l = { cur->val, 0 };
			pair<int, int> r = { cur->val, 0 };

			if (start <= cur->left->end)
				l = search(cur->left, start, min(end, cur->left->end));
			if (end >= cur->right->start)
				r = search(cur->right, max(start, cur->right->start), end);

			if (l.first == r.first)
				return { l.first, l.second + r.second };
			else if (l.second <= r.second)
				return { r.first, r.second - l.second };
			else
				return { l.first, l.second - r.second };
		}
	};

	class MajorityChecker {
	public:
		SegmentModeTree* stree;
		unordered_map<int, vector<int>> m;
		MajorityChecker(vector<int>& arr) {
			for (int i = 0; i < arr.size(); ++i)
				m[arr[i]].push_back(i);
			stree = new SegmentModeTree(arr);
		}

		int query(int left, int right, int threshold) {
			pair<int, int> p = stree->search(stree->head, left, right);
			auto itL = lower_bound(m[p.first].begin(), m[p.first].end(), left);
			auto itR = upper_bound(m[p.first].begin(), m[p.first].end(), right);
			return itR - itL + 1 > threshold ? p.first : -1;
		}
	};