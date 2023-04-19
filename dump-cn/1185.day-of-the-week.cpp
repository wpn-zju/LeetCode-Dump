class Solution {
public:
	bool checkR(int i) {
		return i % 4 == 0 && i % 100 != 0 || i % 400 == 0;
	}

	string dayOfTheWeek(int day, int month, int year) {
		vector<int> m{ 0,31,59,90,120,151,181,212,243,273,304,334 };
		vector<int> mr{ 0,31,60,91,121,152,182,213,244,274,305,335 };
		int count = day + (checkR(year) ? mr[month - 1] : m[month - 1]);
		for (int i = 1971; i < year; ++i)
			count += 365 + checkR(i);
		switch (count % 7)
		{
		case 0:
			return "Thursday";
		case 1:
			return "Friday";
		case 2:
			return "Saturday";
		case 3:
			return "Sunday";
		case 4:
			return "Monday";
		case 5:
			return "Tuesday";
		default:
			return "Wednesday";
		}
	}
};