class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
		// Using stack
		stack<int> s;
		int min = INT_MIN;
		for (int i : preorder) {
			if (i < min)
				return false;
			while (!s.empty() && s.top() < i) {
				min = max(min, s.top());
                s.pop();
			}
			s.push(i);
		}
		return true;
    }
};