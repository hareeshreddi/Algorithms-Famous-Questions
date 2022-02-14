class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>us(wordDict.begin(),wordDict.end());
        int k=s.length();
        vector<bool>dp(k,false);
        dp[0]=true;
        for(int i=1;i<=k;i++)
            for(int j=i-1;j>=0;j--){
                if(i-j>20) break;
                if(dp[j] && us.find(s.substr(j,i-j))!=us.end()){
                    dp[i]=true;break;
                }
            }
        return dp[k];
    }
};