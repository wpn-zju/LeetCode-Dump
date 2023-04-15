class MyQueue {
public:
	stack<int> stack1;
	stack<int> stack2;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		while (stack1.size()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int result = stack2.top();
		stack2.pop();
		while (stack2.size()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return result;
	}

	/** Get the front element. */
	int peek() {
		while (stack1.size()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int result = stack2.top();
		while (stack2.size()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return result;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stack1.empty();
	}
};