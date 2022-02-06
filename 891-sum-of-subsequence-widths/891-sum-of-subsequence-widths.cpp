class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,mod=1e9+7;
        long k=1;
        for(int i=0;i<nums.size();++i){
            ans=(ans+(k*nums[i])%mod)%mod;
            ans=(ans-(k*nums[nums.size()-i-1])%mod)%mod;
            k=(k*2)%mod;
        }
        return (ans+mod)%mod;
    }
};