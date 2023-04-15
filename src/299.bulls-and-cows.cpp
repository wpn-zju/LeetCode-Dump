class Solution {
public:
	string getHint(string secret, string guess) {
		int bulls = 0;
		int cows = 0;
		vector<int> charMap(10, 0);
		for (int i = 0; i < secret.length(); ++i) {
			charMap[secret[i] - '0']++;
			if (secret[i] == guess[i])
				bulls++;
		}
		for (int i = 0; i < secret.length(); ++i) {
			if (charMap[guess[i] - '0']) {
				charMap[guess[i] - '0']--;
				cows++;
			}
		}
		return to_string(bulls) + 'A' + to_string(cows - bulls) + 'B';
	}
};