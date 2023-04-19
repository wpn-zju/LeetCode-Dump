class Solution {
public:
	class NumberTrieNode {
	public:
		NumberTrieNode* zero = nullptr;
		NumberTrieNode* one = nullptr;
	};

	bool int32GetBit(int& num, int digit) {
		return num >> digit & 1;
	}

	int findMaximumXOR(vector<int>& nums) {
		NumberTrieNode* head = new NumberTrieNode();

		for (int i : nums) {
			NumberTrieNode* cur = head;
			for (int d = 31; d >= 0; --d) {
				bool digit = int32GetBit(i, d);
				if (digit) {
					if (!cur->one)
						cur->one = new NumberTrieNode();
					cur = cur->one;
				}
				else {
					if (!cur->zero)
						cur->zero = new NumberTrieNode();
					cur = cur->zero;
				}
			}
		}

		int result = 0;
		for (int i : nums) {
			int tmp = 0;
            NumberTrieNode* cur = head;
			for (int d = 31; d >= 0; --d) {
				tmp <<= 1;
				bool digit = int32GetBit(i, d);
				if (digit) {
					if (cur->zero) {
						tmp++;
						cur = cur->zero;
					}
					else
						cur = cur->one;
				}
				else {
					if (cur->one) {
						tmp++;
						cur = cur->one;
					}
					else
						cur = cur->zero;
				}
			}
			result = max(result, tmp);
		}
		return result;
	}
};