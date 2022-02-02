class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>um;
        //2,3,4,5 =>30; 4,5,6,7=>120; 6,7,8,9=>480
        for(const vector<int>&v:reservedSeats)
            if(v[1]!=1 && v[1]!=10)
                um[v[0]]|=(1<<(v[1]-1));
        int ans=0;
        for(const pair<int,int>&p:um){
            int k=0;
            if((p.second&30)==0) ++k;
            if((p.second&480)==0) ++k;
            if(k==0 && (p.second&120)==0) ++k;
            ans+=k;
        }
        ans+=2*(n-um.size());
        return ans;
    }
};