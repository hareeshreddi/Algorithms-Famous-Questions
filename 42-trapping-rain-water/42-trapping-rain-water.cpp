class Solution {
public:
    int trap(vector<int>& height) {
        int k=height.size(),ans=0;
        vector<int>right(k,0);
        right[k-1]=height[k-1];
        int r=height[0];
        for(int i=k-2;i>=0;--i) right[i]=max(height[i],right[i+1]);
        for(int i=0;i<k-1;++i){
            r=max(r,height[i]);
            ans+=(min(r,right[i])-height[i]);
        }
        return ans;
    }
};