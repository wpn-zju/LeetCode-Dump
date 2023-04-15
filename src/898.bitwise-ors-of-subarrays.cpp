class Solution {
public:
int subarrayBitwiseORs(vector<int>& A) {
	unordered_set<int> result;
	vector<int> last;
	for (int& i : A) {
		vector<int> cur{ i };
		result.insert(i);
		int prev = i;
		for (int& j : last) {
			if ((i |= j) ^ prev) {
				cur.push_back(i);
				result.insert(i);
				prev = i;
			}
		}
		last = move(cur);
	}
	return result.size();
}
};