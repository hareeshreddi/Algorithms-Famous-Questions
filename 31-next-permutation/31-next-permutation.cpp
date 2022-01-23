class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k=nums.size()-2;
        if(k==-1) return;
        while(k>=0 && nums[k]>=nums[k+1]) --k;
        if(k>=0){//other than special case of k=-1(total non increasing sequence)
            int p=nums.size()-1;
            while(nums[p]<=nums[k]) --p;
            swap(nums[k++],nums[p]);
        } else k=0;
        for(int j=nums.size()-1;k<=j;++k,--j) swap(nums[k],nums[j]);
    }
};