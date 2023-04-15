class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int mx = INT_MIN, imn = 1, imx = 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] < 0)
				swap(imn, imx);	
			imx = max(nums[i], imx * nums[i]);
			imn = min(nums[i], imn * nums[i]);
			mx = max(mx, imx);
		}
		return mx;
	}
};