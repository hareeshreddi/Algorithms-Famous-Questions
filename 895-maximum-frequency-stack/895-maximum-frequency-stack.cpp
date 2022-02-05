class FreqStack {
public:
    FreqStack() {
    }
    
    void push(int val) {
        const int k=(++freq[val]);
        if(store.size()<k){
            vector<int>temp(1,val);
            store.push_back(temp); 
        } else store[k-1].push_back(val);
        max_freq=max(max_freq,k);
    }
    
    int pop() {
        int ans=store[max_freq-1].back();
        store[max_freq-1].pop_back();
        --freq[ans];
        if(store[max_freq-1].empty()){
            store.pop_back();
            --max_freq;
        }
        return ans;
        
    }
private:
    vector<vector<int>>store;//storage
    vector<int>temp;
    unordered_map<int,int>freq;//frequency mapper
    int max_freq=0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */