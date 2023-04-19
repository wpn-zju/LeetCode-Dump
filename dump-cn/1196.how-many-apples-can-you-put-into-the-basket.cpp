static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
		int result = 0;
		int money = 5000;
		for (int& i : arr)
			if ((money -= i) >= 0)
				++result;
            else
                break;
		return result;
	}
};