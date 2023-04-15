class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int P) {
		int result = 0;
		sort(tokens.begin(), tokens.end());
		int ptr1 = 0;
		int ptr2 = tokens.size() - 1;
		int cur = 0;
		while (ptr1 <= ptr2) {
			if (P >= tokens[ptr1]) {
				P -= tokens[ptr1];
				cur++;
				result = max(result, cur);
				ptr1++;
			}
			else if(cur){
				P += tokens[ptr2];
				cur--;
				ptr2--;
			}
            else
                break;
		}
		return result;
	}
};