class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int ptrl = 0, ptrr = arr.size() - k;
		while (ptrl < ptrr) {
			int mid = ptrl + (ptrr - ptrl >> 1);
			if (x - arr[mid] > arr[mid + k] - x)
				ptrl = mid + 1;
			else
				ptrr = mid;
		}
		return vector<int>(arr.begin() + ptrl, arr.begin() + ptrl + k);
	}
};