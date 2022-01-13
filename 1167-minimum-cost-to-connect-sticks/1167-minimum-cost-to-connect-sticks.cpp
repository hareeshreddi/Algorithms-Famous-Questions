class Solution {
public:
    struct comp{
      bool operator()(const int &v1,const int &v2){
          return v1>v2;
      }  
    };
    int connectSticks(vector<int>& sticks) {
        int ans=0;
        priority_queue<int,vector<int>,comp>pq(sticks.begin(),sticks.end());
        while(pq.size()>1){
            int r=pq.top();pq.pop();
            int f=pq.top();pq.pop();
            ans+=(r+f);
            pq.push(r+f);
        }
        return ans;
    }
};