class MovingAverage {
public:
	int size = 0;
	int sum = 0;
    int curSize = 0;
	queue<int> myQueue;
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		this->size = size;
	}

	double next(int val) {
		myQueue.push(val);
        sum += val;
        curSize++;
		if (curSize > size) {
			sum -= myQueue.front();
            curSize--;
			myQueue.pop();
		}
		return (double)sum / curSize;
	}
};