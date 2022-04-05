class BoundedBlockingQueue {
private:
    int capacity;
    condition_variable_any cv_push,cv_pop;
    shared_mutex smtx;
    queue<int>q;
public:
    BoundedBlockingQueue(int capacity) {
        this->capacity=capacity;
    }
    
    void enqueue(int element) {
        unique_lock<shared_mutex>ul(smtx);
        cv_push.wait(ul,[this](){return q.size()!=capacity;});
        q.push(element);
        ul.unlock();
        cv_pop.notify_one();
    }
    
    int dequeue() {
        unique_lock<shared_mutex>ul(smtx);
        cv_pop.wait(ul,[this](){return q.size()!=0;});
        int ans=q.front();
        q.pop();
        ul.unlock();
        cv_push.notify_one();
        return ans;
    }
    
    int size() {
        shared_lock<shared_mutex>sl(smtx);
        return q.size();
    }
};