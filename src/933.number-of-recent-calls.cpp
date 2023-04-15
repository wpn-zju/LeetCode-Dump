class RecentCounter {
public:
	queue<int> pingQueue;
	RecentCounter() {

	}

	int ping(int t) {
		pingQueue.push(t);
		while (pingQueue.front() < t - 3000)
			pingQueue.pop();
		return pingQueue.size();
	}
};