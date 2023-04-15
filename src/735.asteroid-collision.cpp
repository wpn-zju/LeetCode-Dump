class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> s;
		for (int& i : asteroids) {
			while (!s.empty() && s.top() > 0 && -i > s.top())
				s.pop();
			if (s.empty() || i > 0 || s.top() < 0)
				s.push(i);
			else if (s.top() == -i)
				s.pop();
		}
		vector<int> result;
		while (!s.empty()) {
			result.push_back(s.top());
			s.pop();
		}
		reverse(result.begin(), result.end());
		return result;
	}
};