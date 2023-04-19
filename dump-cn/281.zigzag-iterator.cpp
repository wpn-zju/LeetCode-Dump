class ZigzagIterator {
public:
	vector<int>* p1;
	vector<int>* p2;
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	bool flag1 = true;
	ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		p1 = &v1;
		p2 = &v2;
        if(p1->size())
		    iter1 = p1->begin();
		if(p2->size())
            iter2 = p2->begin();
	}

	int next() {
		int result = 0;
		if (p1->size() && (flag1 || iter2 == p2->end()) && iter1 != p1->end()) {
			result = *iter1;
			iter1++;
		}
		else if (p2->size() && iter2 != p2->end()) {
			result = *iter2;
			iter2++;
		}
		flag1 = !flag1;
		return result;
	}

	bool hasNext() {
		return iter1 != p1->end() || iter2 != p2->end();
	}
};