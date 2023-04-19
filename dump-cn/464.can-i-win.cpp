static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal)
			return true;
		if (maxChoosableInteger * (maxChoosableInteger + 1) < 2 * desiredTotal)
			return false;
		unordered_map<int, bool> visited;
		return canIWin(desiredTotal, 0, visited, maxChoosableInteger);
	}

	bool canIWin(int target, int used, unordered_map<int, bool>& visited, int& maxLength) {
		if (visited.count(used))
			return visited[used];
		for (int i = 0; i < maxLength; ++i)
			if ((used & (1 << i)) == 0)
				if (target <= i + 1 || !canIWin(target - i - 1, used | (1 << i), visited, maxLength))
					return visited[used] = true;
		return visited[used] = false;
	}
};