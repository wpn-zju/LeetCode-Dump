class MinStack {
public:
    int timeStamp;
    map<int, int> data;
    map<int, vector<int>> myMap;
    /** initialize your data structure here. */
    MinStack() {
        timeStamp = 0;
    }
    
    void push(int x) {
        data[timeStamp] = x;
        if(myMap.count(x))
            myMap[x].push_back(timeStamp);
        else
            myMap[x] = vector<int>{timeStamp};
        timeStamp++;
    }
    
    void pop() {
        map<int, int>::iterator iter = data.end();
        iter--;
        int result = iter->second;
        data.erase(iter);
        myMap[result].pop_back();
        if(myMap[result].size() == 0)
            myMap.erase(result);
    }
    
    int top() {
        map<int, int>::iterator iter = data.end();
        iter--;
        return iter->second;
    }
    
    int getMin() {
        return myMap.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */