class MyCircularDeque {
public:
	int head = 1;
	int tail = 0;
	int count = 0;
	vector<int> queueVec;

	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		queueVec = vector<int>(k, -1);
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (isFull())
			return false;
		head = (head - 1 + queueVec.size()) % queueVec.size();
		queueVec[head] = value;
		++count;
		return true;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (isFull())
			return false;
		tail = (tail + 1) % queueVec.size();
		queueVec[tail] = value;
		++count;
		return true;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (isEmpty())
			return false;
		queueVec[head] = -1;
		head = (head + 1) % queueVec.size();
		--count;
		return true;
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (isEmpty())
			return false;
		queueVec[tail] = -1;
		tail = (tail - 1 + queueVec.size()) % queueVec.size();
		--count;
		return true;
	}

	/** Get the front item from the deque. */
	int getFront() {
		return queueVec[head];
	}

	/** Get the last item from the deque. */
	int getRear() {
		return queueVec[tail];
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return !count;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return count == queueVec.size();
	}
};