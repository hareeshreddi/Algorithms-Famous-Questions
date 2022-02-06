class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1) return nums[0]==target?0:-1;
        int i=0,j=nums.size()-1;
        while(i<j){
            const int m=(i+j)/2;
            if(nums[i]<nums[j]) break;
            else if(j==i+1){
                i=j;break;
            }
            if(nums[m]>nums[i]) i=m+1;
            else j=m;
        }//i has the smallest number location
        int s=i;
        i=0,j=nums.size()-1;
        if(target>nums[(s+j)%(j+1)] || target<nums[s]) return -1;
        if(target<nums[0]) i=s;
        else j=(s+j)%(j+1);
        while(i<j){
            const int m=(i+j)/2;
            if(nums[m]<target) i=m+1;
            else j=m;
        }
        return nums[i]==target?i:-1;
    }
};