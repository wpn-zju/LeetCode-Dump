class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0, c20 = 0;
        for(int& i : bills){
            switch(i){
                case 5:
                    ++c5;
                    break;
                case 10:
                    if(!c5)
                        return false;
                    --c5;
                    ++c10;
                    break;
                case 20:
                    if(c10 && c5){
                        --c10;
                        --c5;
                    }
                    else if (c5 >= 3)
                        c5 -= 3;
                    else
                        return false;
                    break;
            }            
        }
        return true;
    }
};