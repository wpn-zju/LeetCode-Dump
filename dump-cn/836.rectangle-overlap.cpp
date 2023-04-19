static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (int64_t)(rec2[0] - rec1[2]) * (rec2[2] - rec1[0]) < 0 && (int64_t)(rec2[1] - rec1[3]) * (rec2[3]-rec1[1]) < 0; 
	}
};