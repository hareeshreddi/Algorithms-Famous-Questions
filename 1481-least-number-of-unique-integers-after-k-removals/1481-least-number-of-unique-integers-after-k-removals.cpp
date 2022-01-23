class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>um;
        for(const auto &p:arr) ++um[p];
        priority_queue<int,vector<int>,greater<int>>pq;
        for(const pair<int,int> &p:um) pq.push(p.second);
        while(!pq.empty()){
            if(pq.top()<=k){
                k-=pq.top();
                pq.pop();
            }
            else break;
        }
        return pq.size();
    }
};