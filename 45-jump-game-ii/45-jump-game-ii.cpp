class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,far=0,cur=0;
        for(int i=0;i<nums.size()-1;i++){
            far=max(far,i+nums[i]);
            if(i==cur){
                ++jump;
                cur=far;
                if(cur>=nums.size()-1) return jump;
            }
        }
        return jump;
    }
};

//O(N^2) DP Solution ==>>
// vector<int>dp(nums.size(),INT_MAX);
// dp[0]=0;
// for(int i=1;i<nums.size();i++)
//     for(int j=0;j<i;j++)
//         if(dp[j]!=INT_MAX && j+nums[j]>=i)
//             dp[i]=min(dp[i],dp[j]+1);
// return dp[nums.size()-1];