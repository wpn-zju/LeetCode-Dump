void QuickSort(vector<int>& array, vector<int>& index, int start, int last) {
	int i = start;
	int j = last;

	if (i < j)
	{
        int temp = array[i];
	    int tempIndex = index[i];
        
		while (i < j)
		{
			while (i < j &&  array[j] >= temp)
				j--;
			if (i < j)
			{
				array[i] = array[j];
				index[i] = index[j];
				i++;
			}

			while (i < j && temp > array[i])
				i++;
			if (i < j)
			{
				array[j] = array[i];
				index[j] = index[i];
				j--;
			}
		}

		array[i] = temp;
		index[i] = tempIndex;
		QuickSort(array, index, start, i - 1);
		QuickSort(array, index, i + 1, last);
	}
}

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i = 0;
		int j = nums.size() - 1;
		vector<int> orderedArray = nums;
		vector<int> index;
		for (int k = 0; k < nums.size(); ++k)
			index.push_back(k);
		vector<int> result;

		QuickSort(orderedArray, index, 0, nums.size() - 1);

		while (i != j)
		{
			if (orderedArray[i] + orderedArray[j] == target)
				break;
			else if (orderedArray[i] + orderedArray[j] < target)
				++i;
			else
				--j;
		}

		result.push_back(index[i]);
		result.push_back(index[j]);
		return result;
	}
};