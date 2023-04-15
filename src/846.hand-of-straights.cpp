class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W != 0)
          return false;
        map<int, int> m;
        
        for(int card : hand){
            if(m.count(card) > 0)
              m[card] += 1;
            else
              m.insert({card, 1});
        }
      
        while(!m.empty()){
          auto it = m.begin();
          int start = it->first;

          for(int i = start; i < start + W; i++){
            if(m[i] == 0)
              return false;
            if(m[i] == 1)
              m.erase(i);
            else
              m[i] -= 1;
          }
        }
        return true;
    }
};