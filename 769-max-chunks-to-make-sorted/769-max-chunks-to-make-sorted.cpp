class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,max1=-1;
        for(int i=0;i<arr.size();i++){
            max1=max(max1,arr[i]);
            if(max1==i)
                ++ans;
        }
        return ans;
    }
};