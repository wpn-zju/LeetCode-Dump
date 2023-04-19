class MyStack {
public:
	queue<int> queue1;
	queue<int> queue2;
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		queue1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		while (queue1.size() > 1) {
			queue2.push(queue1.front());
			queue1.pop();
		}
		int result = queue1.front();
		while (queue2.size()) {
			queue1.push(queue2.front());
			queue2.pop();
		}
		queue1.pop();
		return result;
	}

	/** Get the top element. */
	int top() {
		while (queue1.size() > 1) {
			queue2.push(queue1.front());
			queue1.pop();
		}
		int result = queue1.front();
		queue2.push(queue1.front());
		queue1.pop();
		while (queue2.size()) {
			queue1.push(queue2.front());
			queue2.pop();
		}
		return result;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return queue1.empty();
	}
};