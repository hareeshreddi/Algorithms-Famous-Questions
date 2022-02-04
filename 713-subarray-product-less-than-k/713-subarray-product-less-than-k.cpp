class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0 || k==1) return 0;
        int ans=0,product=1,i=0;
        for(int j=0;j<nums.size();j++){
            product*=nums[j];
            while(product>=k) product/=nums[i++]; 
            ans+=(j-i+1);
        }
        return ans;
    }
};