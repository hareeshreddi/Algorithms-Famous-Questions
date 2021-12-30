class Solution {
public:
    static bool func(const vector<int>&v1,const vector<int>&v2)//increasing order w.r.t start time then increasing order w.r.t value
    {
        if(v1[0]==v2[0]) return v1[1]<v2[1];
        return v1[0]<v2[0];
    }
    struct comp{//decreasing order w.r.t end time then increasing order w.r.t value
        bool operator() ( vector<int>&v1, vector<int>&v2)
        {
            if(v1[0]==v2[0])
                return v1[1]<v2[1];
            return v1[0]>v2[0];
        }
    };
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans=0,max1=0;
        sort(events.begin(),events.end(),func);
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        for(int i=0;i<events.size();i++)
        {
            while(!pq.empty() && pq.top()[0]<events[i][0]){
                max1=max(max1,pq.top()[1]);
                pq.pop();
            }
            ans=max(ans,max1+events[i][2]);
            pq.push({events[i][1],events[i][2]});
        }
        return ans;
    }
};