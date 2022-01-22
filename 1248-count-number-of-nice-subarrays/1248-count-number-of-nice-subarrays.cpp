class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0,i=0,cur=0,c=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]&1){ 
                cur++;
                if(cur>=k){
                    c=1;
                    while(!(nums[i]&1)) i++,c++;
                    i++;
                    ans+=c;
                    if(cur==k+1) cur=k;
                }
            }
            else if(cur==k){
                ans+=c;
            }
        }
        return ans;
    }
};