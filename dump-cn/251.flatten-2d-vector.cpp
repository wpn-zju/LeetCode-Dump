class Vector2D {
public:
	vector<vector<int>>* vec;
	vector<vector<int>>::iterator outIter;
	vector<int>::iterator inIter;

	Vector2D(vector<vector<int>>& v) {
		vec = &v;
		if (vec->size()) {
			outIter = vec->begin();
			while (outIter != vec->end() && !outIter->size())
				outIter++;
			if (outIter != vec->end())
				inIter = outIter->begin();
		}
	}

	int next() {
		int result = *inIter;
		inIter++;
		if (inIter == outIter->end()) {
			outIter++;
			while (outIter != vec->end() && !outIter->size())
				outIter++;
			if (outIter != vec->end())
				inIter = outIter->begin();
		}
		return result;
	}

	bool hasNext() {
		return vec->size() && outIter != vec->end();
	}
};