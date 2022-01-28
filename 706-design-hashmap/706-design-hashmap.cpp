class MyHashMap {
private:
    vector<list<pair<int,int>>>v;
    const static int size1=1997;
    const static int factor = 1e9+7;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        v.resize(size1);
    }
    int hash(int key){
        return ((long)factor*key%size1);
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        list<pair<int,int>>&list=v[hash(key)];
        for(pair<int,int>&val:list){
            if(val.first==key){
                val.second=value;
                return;
            }
        }
        list.push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        const list<pair<int,int>>&list=v[hash(key)];
        for(const pair<int,int>&val:list){
            if(val.first==key)
                return val.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        list<pair<int,int>>&list1=v[hash(key)];
        for(list<pair<int,int>>::iterator it=list1.begin();it!=list1.end();++it)
            if(it->first==key){
                list1.erase(it);
                return;
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */