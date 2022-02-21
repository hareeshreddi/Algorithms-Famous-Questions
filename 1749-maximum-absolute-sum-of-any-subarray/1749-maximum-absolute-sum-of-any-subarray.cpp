class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=abs(nums[0]),cur1=nums[0],cur2;
        if(cur1<0){
            cur2=cur1;
            cur1=0;
        } else cur2=0;
        for(int i=1;i<nums.size();i++){
            cur1+=nums[i];
            ans=max(ans,cur1);
            if(cur1<0) cur1=0;
            cur2+=nums[i];
            ans=max(ans,-1*cur2);
            if(cur2>0) cur2=0;
        }
        return ans;
    }
};