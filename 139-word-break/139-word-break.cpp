class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>us(wordDict.begin(),wordDict.end());
        int k=s.length();
        vector<bool>dp(k,false);
        dp[0]=true;
        for(int i=1;i<=k;i++)
            for(int j=i;j>0;j--){
                if(i-j+1>20) break;
                if(dp[j-1] && us.find(s.substr(j-1,i-j+1))!=us.end()){
                    dp[i]=true;break;
                }
            }
        return dp[k];
    }
};