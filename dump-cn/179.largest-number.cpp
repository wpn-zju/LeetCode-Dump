class Solution {
public:
   static  bool cmp(string a,string b){
        int len1 = (int)a.length(),len2 = (int)b.length();
        if(len1 == len2) return a < b; // 不写就报错
        int i = 0,j = 0;
        while(i < len1 && j < len2){
            if(a[i] > b[j]) return false;
            else if(a[i] < b[j]) return true;
            i++,j++;
            if(i == len1 && j == len2) return true;
            if(i == len1){
                i = 0;
            }
            if(j == len2){
                j = 0;
            }
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        // sort(nums.begin(),nums.end());
        int len = (int) nums.size();
        for(int i = 0;i < len; i++){
            ans.push_back(to_string(nums[i]));
        }
        sort(ans.begin(),ans.end(),cmp);
        string tmp = "";
        for(int i = len - 1;i >= 0; i--){
            tmp = tmp + ans[i];
        }
        int i = 0;
        int tmp_len = (int)tmp.length();
        while(i < tmp_len){
            if(tmp[i] != '0') break;
            else i++;
        }
        if(i == tmp_len) return "0";
        else
        return tmp.substr(i);
    }
};