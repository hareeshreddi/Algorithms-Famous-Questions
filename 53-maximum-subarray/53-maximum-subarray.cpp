class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // findStartAndEndofMaxSubArray(nums);
        int ans=nums[0],cur=max(nums[0],0);
        for(int i=1;i<nums.size();i++){
            ans=max(ans,cur+=nums[i]);
            if(cur<0) cur=0;
        }
        return ans;
    } /*
    void findStartAndEndofMaxSubArray(vector<int>&nums){
        //finding start & end indexes of max subarray
        int start=0,end=0,currentStart=0;
        int ans=nums[0],cur=ans;
        if(cur<0){
            cur=0;
            currentStart=1;
        }
        for(int i=1;i<nums.size();i++){
            cur+=nums[i];
            if(cur>ans){//updating global max
                start=currentStart;
                end=i;
                ans=cur;
            }
            if(cur<0){//updating current max
                cur=0;
                currentStart=i+1;
            }
        }
        //finally start-end index subarray will have our answer  
    } */
};