class NumArray {
public:
    vector<int>dp;
    NumArray(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        dp=nums;
    }
    
    int sumRange(int left, int right) {
        if(!left) return dp[right];
        return dp[right]-dp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */