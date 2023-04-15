class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int ptr = 0;
		while (ptr < bits.size() - 1)
			ptr += bits[ptr] + 1;
		return ptr < bits.size();
	}
};