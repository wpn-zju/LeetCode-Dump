// 列表中的项或者为一个整数，或者是另一个列表
class NestedIterator {
public:
	stack<vector<NestedInteger>::const_iterator> begin;
	stack<vector<NestedInteger>::const_iterator> end;
	NestedIterator(vector<NestedInteger>& nestedList) {
		begin.push(nestedList.begin());
		end.push(nestedList.end());
	}

	int next() {
		int result = begin.top()->getInteger();
		while (++begin.top() == end.top()) {
			begin.pop();
			end.pop();
			if (begin.empty())
				break;
		}
		return result;
	}

	bool hasNext() {
		while (!begin.empty()) {
			if (begin.top() == end.top()) {
				begin.pop();
				end.pop();
				if (begin.empty())
					return false;
				begin.top()++;
				continue;
			}
			if (begin.top()->isInteger())
				return true;
			const vector<NestedInteger>* list = &(begin.top()->getList());
			begin.push(list->begin());
			end.push(list->end());
		}
		return false;
	}
};