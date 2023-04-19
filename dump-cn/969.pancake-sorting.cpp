class Solution {
public:
	vector<int> pancakeSort(vector<int>& A) {
		vector<int> result;
		int sortedNumber = 0;
		for (int n = 0; n < A.size(); ++n) {
			int max = INT_MIN;
			int maxIndex = -1;
			for (int i = 0; i < A.size() - sortedNumber; ++i) {
				if (A[i] > max) {
					max = A[i];
					maxIndex = i;
				}
			}
			if (maxIndex != A.size() - sortedNumber - 1) {
                if(maxIndex != 0){
                    reverse(A.begin(), A.begin() + maxIndex + 1);
                    result.push_back(maxIndex + 1);
                }	
				reverse(A.begin(), A.end() - sortedNumber);
				result.push_back(A.size() - sortedNumber);
			}
			++sortedNumber;
		}
		return result;
	}
};