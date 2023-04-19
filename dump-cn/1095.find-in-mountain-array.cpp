/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int start = 0;
		int end = mountainArr.length() - 2;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (mountainArr.get(mid) < mountainArr.get(mid + 1))
				start = mid + 1;
			else
				end = mid;
		}
		int mid = start;
		end = mid;
		start = 0;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (mountainArr.get(mid) < target)
				start = mid + 1;
			else
				end = mid;
		}
		if (mountainArr.get(start) == target)
			return start;
		start = mid + 1;
		end = mountainArr.length() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (mountainArr.get(mid) > target)
				start = mid + 1;
			else
				end = mid;
		}
		return mountainArr.get(start) == target ? start : -1;
	}
};