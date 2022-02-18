class LRUCache {
private:
    list<pair<int,int>>p;
    unordered_map<int,list<pair<int,int>>::iterator>um;
    int r;
public:
    LRUCache(int capacity) {
        // p.clear();
        // um.clear();
        r=capacity;
    }
    
    int get(int key) {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator it=um.find(key);
        if(it!=um.end()){
            if(key!=p.front().first){
                p.push_front({key,(it->second)->second});
                p.erase(it->second);
                (it->second)=p.begin();
            }
            return p.front().second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator it=um.find(key);
        if(it!=um.end()){
            if(key!=p.front().first) {
                p.erase(it->second);
                p.push_front({key,value});
                (it->second)=p.begin();
            } 
            else p.front().second=value;
        } 
        else{
            if(r==um.size()){
                um.erase(p.back().first);
                p.pop_back();
            }
            p.push_front({key,value});
            um[key]=p.begin();  
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */