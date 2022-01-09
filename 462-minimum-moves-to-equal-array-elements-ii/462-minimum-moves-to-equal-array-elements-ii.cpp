class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans=0,i=0;
        for(;i<nums.size()/2;i++)
            ans+=(-nums[nums.size()/2]+nums[i]);
        for(;i<nums.size();i++)
            ans+=(-nums[i]+nums[nums.size()/2]);
        return ans;
    }
};