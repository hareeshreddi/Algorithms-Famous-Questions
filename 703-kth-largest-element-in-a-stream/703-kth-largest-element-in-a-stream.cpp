class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        s=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>s) pq.pop();//to handle case at bottom
        return pq.top();
    }
private:
    struct comp{
        bool operator() (const int &x,const int &y){
            return x>y;
        }
    };
    int s;
    priority_queue<int,vector<int>,comp>pq;//min pq
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//special case of empty array at start
// ["KthLargest","add","add","add","add","add"]
// [[1,[]],[-3],[-2],[-4],[0],[4]]