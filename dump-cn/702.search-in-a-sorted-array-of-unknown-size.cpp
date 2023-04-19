// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
	int search(const ArrayReader& reader, int target) {
		int start = 0;
		int end = 20000;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (reader.get(mid) < target)
				start = mid + 1;
			else
				end = mid;
		}
		return reader.get(start) == target ? start : -1;
	}
};