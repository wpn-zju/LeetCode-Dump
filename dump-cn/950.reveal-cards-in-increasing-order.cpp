class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		sort(deck.begin(), deck.end(), greater<int>());
		list<int> result;
		for (int& i : deck) {
			if (!result.empty()) {
				result.push_front(result.back());
				result.pop_back();
			}
			result.push_front(i);
		}
		return vector<int>(result.begin(), result.end());
	}
};