	class StockSpanner {
	public:
		int timestamp;
		stack<int> t;
		stack<int> s;

		StockSpanner() {
			timestamp = 0;
			t.push(0);
			s.push(INT_MAX);
		}

		int next(int price) {
			while (price >= s.top()) {
				s.pop();
				t.pop();
			}
			int result = ++timestamp - t.top();
			s.push(price);
			t.push(timestamp);
			return result;
		}
	};