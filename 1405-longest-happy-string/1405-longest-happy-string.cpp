class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        while(pq.size()>1){
            auto one=pq.top();pq.pop();
            auto two=pq.top();pq.pop();
            //add first ele
            ans+=one.second;
            one.first-=1;
            if(one.first){
                ans+=one.second;
                one.first-=1;
            }
            //add second ele
            ans+=two.second;
            two.first-=1;
            if(two.first && (two.first>=one.first)){
                ans+=two.second;
                two.first-=1;
            }
            // cout<<"ans::"<<ans<<"\n";
            if(one.first) pq.push(one);
            if(two.first) pq.push(two);
        }
        if(pq.empty()) return ans;
        //add remainining ele
        ans+=pq.top().second;
        if(pq.top().first>=2) ans+=pq.top().second;
        return ans;
    }
};