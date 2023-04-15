class Logger {
public:
	unordered_map<string, int> myMap;
	/** Initialize your data structure here. */
	Logger() {

	}

	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
		If this method returns false, the message will not be printed.
		The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		if (!myMap.count(message) || myMap.count(message) && timestamp - myMap[message] >= 10) {
			myMap[message] = timestamp;
			return true;
		}
		return false;
	}
};