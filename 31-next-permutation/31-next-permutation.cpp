class Solution {
public:
    //example 1,5,8,4,7,6,6,5,5,4,4,4,3,2,2,2,1
    void nextPermutation(vector<int>& nums) {
        int k=nums.size()-2;
        if(k==-1) return;
        while(k>=0 && nums[k]>=nums[k+1]) --k;
        if(k>=0){
            int p=nums.size()-1;
            while(nums[p]<=nums[k]) --p;
            swap(nums[k++],nums[p]);
        } else k=0;//special case of k=-1(total non increasing sequence)
        for(int j=nums.size()-1;k<j;++k,--j) swap(nums[k],nums[j]);
    }
};