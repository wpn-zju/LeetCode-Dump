class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		unordered_set<int> set2;
		int sum1 = 0;
		int sum2 = 0;
		for (int& i : A)
			sum1 += i;
		for (int& i : B) {
			set2.insert(i);
			sum2 += i;
		}
		int diff = sum1 - sum2 >> 1;
		for (int& i : A)
			if (set2.count(i - diff))
				return{ i, i - diff };
		return{ 0,0 };
	}
};