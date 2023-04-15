class Solution {
public:
	vector<int> transformArray(vector<int>& arr) {
		bool tag = true;
		vector<int> arr2 = arr;
		while (1) {
			bool control = false;
			if (tag) {
				arr2[0] = arr[0];
				arr2.back() = arr.back();
			}
			else {
				arr[0] = arr2[0];
				arr.back() = arr2.back();
			}
			for (int i = 1; i < arr2.size() - 1; ++i) {
				if (tag) {
					if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
						arr2[i] = arr[i] - 1;
						control = true;
					}
					else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
						arr2[i] = arr[i] + 1;
						control = true;
					}
                    else
                        arr2[i] = arr[i];
				}
				else {
					if (arr2[i] > arr2[i - 1] && arr2[i] > arr2[i + 1]) {
						arr[i] = arr2[i] - 1;
						control = true;
					}
					else if (arr2[i] < arr2[i - 1] && arr2[i] < arr2[i + 1]) {
						arr[i] = arr2[i] + 1;
						control = true;
					}
                    else
                        arr[i] = arr2[i];
				}
			}
			tag = !tag;
			if (!control)
				break;
		}
		return tag ? arr : arr2;
	}
};