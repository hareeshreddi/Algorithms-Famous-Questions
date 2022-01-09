class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0,cur=neededTime[0],max1=cur;
        for(int i=1;i<neededTime.size();i++){
            while(i<neededTime.size() && colors[i]==colors[i-1]){
                max1=max(max1,neededTime[i]);
                cur+=neededTime[i++];
            }
            if(neededTime[i-1]!=cur)
                ans+=(cur-max1);
            cur=neededTime[i];max1=cur;
        }
        return ans;
    }
};