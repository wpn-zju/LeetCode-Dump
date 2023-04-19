class Solution {
public:
	int kthGrammar(int N, int K) {
		int count = 0;
		K--;
		for (int i = 0; i < 29; i++)
			if (K & 1 << i)
				count++;
		return count % 2;
	}
};