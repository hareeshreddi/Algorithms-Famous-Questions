class Solution {
public:
    int calcualteMaxRectangleArea(vector<int>&dp){
        int ans=0;
        stack<int>s;
        s.push(-1);
        for(int i=0;i<dp.size();i++){
            while(s.top()!=-1 && dp[s.top()]>dp[i]){
                int k=s.top();s.pop();
                ans=max(ans,dp[k]*(i-s.top()-1));
                // cout<<"i is::"<<i<<" and cur ans is::"<<dp[k]*(i-s.top()-1)<<"\n";
            }
            s.push(i);
        }
        while(s.top()!=-1){
            int k=s.top();s.pop();
            // cout<<"cur ans is::"<<dp[k]*((int)dp.size()-s.top()-1)<<"\n";
            ans=max(ans,dp[k]*((int)dp.size()-s.top()-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        vector<int>dp(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') ++dp[j];
                else dp[j]=0;
                // cout<<dp[j]<<" ";
            }
            // cout<<"\n";
            ans=max(ans,calcualteMaxRectangleArea(dp));
            // cout<<"ans is::"<<ans<<"\n";
        }
        return ans;
    }
};