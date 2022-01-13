class Solution {
public:
    static bool func(const vector<int>&v1,const vector<int>&v2){
        if(v1[1]!=v2[1])
            return v1[1]>v2[1];
        return v1[0]>v2[0];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),func);
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize-boxTypes[i][0]>0)
                ans+=boxTypes[i][0]*boxTypes[i][1];
            else{
                ans+=truckSize*boxTypes[i][1];
                break;
            }
            truckSize-=boxTypes[i][0];
        }
        return ans;
    }
};