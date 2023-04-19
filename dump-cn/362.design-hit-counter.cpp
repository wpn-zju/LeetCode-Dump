class HitCounter {
public:
	queue<int> myQueue;
	/** Initialize your data structure here. */
	HitCounter() {

	}

	/** Record a hit.
		@param timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp) {
		myQueue.push(timestamp);
	}

	/** Return the number of hits in the past 5 minutes.
		@param timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp) {
		while (myQueue.size() && myQueue.front() <= timestamp - 300)
			myQueue.pop();
		return myQueue.size();
	}
};