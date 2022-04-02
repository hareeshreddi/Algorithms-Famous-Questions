class H2O {
private:
    int h;
    int o;
    condition_variable cv;
    mutex mtx;
public:
    H2O() {
        h=2;
        o=1;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul,[this](){return h>0;});
        h--;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if(!h&&!o){
            h=2;o=1;
            ul.unlock();
            cv.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul,[this](){return o>0;});
        o--;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if(!h&&!o){
            h=2;o=1;
            ul.unlock();
            cv.notify_all();
        }
    }
};