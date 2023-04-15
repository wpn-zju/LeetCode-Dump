class MyTime {
public:
	int year;
	int month;
	int day;
	int h;
	int m;
	int s;

	MyTime(string in) {
		year = (in[0] - '0') * 1000 + (in[1] - '0') * 100 + (in[2] - '0') * 10 + (in[3] - '0');
		month = (in[5] - '0') * 10 + (in[6] - '0');
		day =(in[8] - '0') * 10 + (in[9] - '0');
		h = (in[11] - '0') * 10 + (in[12] - '0');
		m = (in[14] - '0') * 10 + (in[15] - '0');
		s = (in[17] - '0') * 10 + (in[18] - '0');
	}

	bool operator<(const MyTime& that) const {
		if (this->year == that.year)
			if (this->month == that.month)
				if (this->day == that.day)
					if (this->h == that.h)
						if (this->m == that.m)
							return this->s < that.s;
						else
							return this->m < that.m;
					else
						return this->h < that.h;
				else
					return this->day < that.day;
			else
				return this->month < that.month;
		else
			return this->year < that.year;
	}

	bool operator<=(const MyTime& that) const {
		if (this->year == that.year)
			if (this->month == that.month)
				if (this->day == that.day)
					if (this->h == that.h)
						if (this->m == that.m)
							return this->s <= that.s;
						else
							return this->m <= that.m;
					else
						return this->h < that.h;
				else
					return this->day < that.day;
			else
				return this->month < that.month;
		else
			return this->year < that.year;
	}

	friend ostream& operator<<(ostream& os, const MyTime& obj) {
		return os << obj.year << ' ' << obj.month << ' ' << obj.day << ' ' << obj.h << ' ' << obj.m << ' ' << obj.s << endl;
	}
};

struct CMPTime {
	bool operator()(const MyTime& a, const MyTime& b) const {
		return a < b;
	}
};

vector<string> logSysTag{ "Year","Month","Day","Hour","Minute","Day" };

class LogSystem {
public:
	map<MyTime, int, CMPTime> data;
	LogSystem() {

	}

	void put(int id, string timestamp) {
		data[MyTime(timestamp)] = id;
	}

	vector<int> retrieve(string s, string e, string gra) {
		MyTime t1(s);
		MyTime t2(e);
		if (gra == logSysTag[0]) {
			t1.month = t1.day = t1.h = t1.m = t1.s = 0;
			t2.month = t2.day = t2.h = t2.m = t2.s = 100;
		}
		else if (gra == logSysTag[1]) {
			t1.day = t1.h = t1.m = t1.s = 0;
			t2.day = t2.h = t2.m = t2.s = 100;
		}
		else if (gra == logSysTag[2]) {
			t1.h = t1.m = t1.s = 0;
			t2.h = t2.m = t2.s = 100;
		}
		else if (gra == logSysTag[3]){
			t1.m = t1.s = 0;
			t2.m = t2.s = 100;
		}
		else if (gra == logSysTag[4]) {
			t1.s = 0;
			t2.s = 100;
		}
		vector<int> result;
		for (auto a : data)
			if ((!(a.first < t1)) && (a.first <= t2))
				result.push_back(a.second);
		return result;
	}
};