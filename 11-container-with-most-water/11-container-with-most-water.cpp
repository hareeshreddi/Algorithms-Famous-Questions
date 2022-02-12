class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,i=0,j=height.size()-1;
        while(i<j){
            if(height[i]<height[j])
                ans=max((j-i)*height[i++],ans);
            else ans=max((j-i)*height[j--],ans);
        }
        return ans;
    }
};