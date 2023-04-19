static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> result(digits.size() + 1, 0);
		result.back() = 1;
		for (int i = digits.size() - 1; i >= 0; --i) {
			result[i + 1] += digits[i];
            if(result[i+1]>9){
                result[i+1]=0;
                result[i] = 1;
            }
		}
		return result[0] ? result : vector<int>(result.begin() + 1, result.end());
	}
};