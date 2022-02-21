class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],cur=max(nums[0],0);
        for(int i=1;i<nums.size();i++){
            ans=max(ans,cur+=nums[i]);
            if(cur<0) cur=0;
        }
        return ans;
    }
};
