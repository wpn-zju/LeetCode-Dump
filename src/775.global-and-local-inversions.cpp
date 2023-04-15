class Solution {
public:
	void mergeSort(vector<int>& nums, vector<int>& tmp, int start, int end, int& result) {
		if (start < end) {
			int mid = (start + end) / 2;
			mergeSort(nums, tmp, start, mid, result);
			mergeSort(nums, tmp, mid + 1, end, result);
			for (int i = start; i <= end; ++i)
				tmp[i - start] = nums[i];
			int ptr1 = start;
			int ptr2 = mid + 1;
			int ptr3 = start;
			while (ptr3 <= end) {
				if (ptr2 > end || ptr1 <= mid && tmp[ptr1 - start] <= tmp[ptr2 - start]){
                    nums[ptr3++] = tmp[ptr1++ - start];
                    result += ptr2 - mid - 1;
                }			
				else
					nums[ptr3++] = tmp[ptr2++ - start];
			}
		}
	}
    
    bool isIdealPermutation(vector<int>& A) {
        int local = 0;
        int global = 0;
        for(int i =0;i<A.size()-1;++i)
            local += A[i] > A[i+1];
        vector<int> tmp(A.size());
		mergeSort(A, tmp, 0, A.size() - 1, global);
        return global == local;
    }
};