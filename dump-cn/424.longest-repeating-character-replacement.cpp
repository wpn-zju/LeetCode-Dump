class Solution {
public:
	int characterReplacement(string s, int k) {
		vector<queue<int>> cVec;
		for (int i = 'A'; i <= 'Z'; ++i)
		{
			queue<int> tmp;
			cVec.push_back(tmp);
		}
		int m = s.size();
		int ptr = 0;
		int max = 0;
		while (ptr != m) {
			queue<int> *q = &cVec[s[ptr] - 'A'];
			q->push(ptr);
			while (ptr - q->front() + 1 - q->size() > k)
				q->pop();
			int cur = ptr - q->front() + 1;
			int kUsed = cur - q->size();
			if (k + q->size() <= m)
				cur = k + q->size();
			else
				cur = m;
			if (cur > max)
				max = cur;
            ptr++;
		}
		return max;
	}
};