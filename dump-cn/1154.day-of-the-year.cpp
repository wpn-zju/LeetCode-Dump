class Solution {
public:
    int dayOfYear(string date) {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        int day = (date[8] - '0') * 10 + (date[9] - '0');
		vector<int> m1{ 0,31,59,90,120,151,181,212,243,273,304,334 };
		vector<int> m2{ 0,31,60,91,121,152,182,213,244,274,305,335 };
        if(year % 4 || year % 100 == 0 && year % 400)
            return m1[month - 1] + day;
        else
            return m2[month - 1] + day;
    }
};