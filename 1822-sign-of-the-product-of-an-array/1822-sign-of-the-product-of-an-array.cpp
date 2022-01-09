class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(auto &u:nums){
            if(!u) return 0;
            else if(u<0) ans*=-1;
        }
        return ans;
    }
};