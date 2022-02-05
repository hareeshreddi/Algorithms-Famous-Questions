class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        v.resize(k);
        m=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        e=(e+1)%m;
        v[e]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(s==e) s=0,e=-1;//special case when single element is present and then dequeued
        else s=(s+1)%m;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:v[s];
    }
    
    int Rear() {
        return isEmpty()?-1:v[e];
    }
    
    bool isEmpty() {
        return e==-1;
    }
    
    bool isFull() {
        return !isEmpty() && (e+1)%m==s;
    }
private:
    vector<int>v;
    int s=0,e=-1,m;
};
//EDGE CASE
//["MyCircularQueue","enQueue","Rear","Rear","deQueue","enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
// [[6],[6],[],[],[],[5],[],[],[],[],[],[]]

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */