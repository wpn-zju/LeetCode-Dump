class MyCircularQueue {
public:
	int head = 1;
	int tail = 0;
	int count = 0;
	vector<int> queueVec;

	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		queueVec = vector<int>(k, -1);
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull())
			return false;
		tail = (tail + 1) % queueVec.size();
		queueVec[tail] = value;
		++count;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty())
			return false;
		queueVec[head] = -1;
		head = (head + 1) % queueVec.size();
		--count;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		return queueVec[head];
	}

	/** Get the last item from the queue. */
	int Rear() {
		return queueVec[tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return !count;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return count == queueVec.size();
	}
};