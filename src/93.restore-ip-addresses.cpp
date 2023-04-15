class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string tmp;
        traverse(ret, s, tmp, 0, 0, 0);
        return ret;
    }

    void traverse(vector<string>& output, string& input, string& curStr, int curNum, int part, int index) {
        if(!isValidIp(curNum)) return;
        if(index == input.size() && part == 3) {
            output.push_back(curStr);
            return;
        }
        else if(index == input.size() || part >= 4){
            return;
        }

        if(curStr.empty() || curStr.back() == '.') {
            curStr += input[index];
            traverse(output, input, curStr, curNum * 10 + input[index] - '0', part, index + 1);
            curStr.pop_back();
        }
        else {
            if(curStr.back() == '0' && curNum == 0) {
                curStr += '.';
                curStr += input[index];
                traverse(output, input, curStr, input[index] - '0', part + 1, index + 1);
                curStr.pop_back();
                curStr.pop_back();
            }
            else {
                curStr += input[index];
                traverse(output, input, curStr, curNum * 10 + input[index] - '0', part, index + 1);
                curStr.pop_back();

                curStr += '.';
                curStr += input[index];
                traverse(output, input, curStr, input[index] - '0', part + 1, index + 1);
                curStr.pop_back();
                curStr.pop_back();
            }
        }
    }

    bool isValidIp(int input) {
        return input >= 0 && input <= 255;
    }
};