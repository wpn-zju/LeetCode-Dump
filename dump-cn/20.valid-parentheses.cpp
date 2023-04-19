class Solution {
public:
 	bool isValid(string s) {
		stack<char> st;
		int index = 0;
		while (index < s.length()) {
			switch (s[index])
			{
			case '(':
				st.push(s[index]);
				break;
			case '[':
				st.push(s[index]);
				break;
			case '{':
				st.push(s[index]);
				break;
			case ')':
				if (st.empty() || st.top() != '(')
					return false;
				else
					st.pop();
				break;
			case ']':
				if (st.empty() || st.top() != '[')
					return false;
				else
					st.pop();				
				break;
			case '}':
				if (st.empty() || st.top() != '{')
					return false;
				else
					st.pop();				
				break;
			default:
				return false;
			}
			index++;
		}

		return st.empty();
	}
};