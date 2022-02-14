class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>us(wordDict.begin(),wordDict.end());
        int k=s.length();
        vector<bool>dp(k,false);
        dp[k]=true;
        for(int i=k-1;i>=0;i--){
            string cur="";
            for(int j=i;j<k;j++){
                cur+=s[j];
                if(cur.length()>20) break;
                if(dp[j+1] && us.find(cur)!=us.end()){
                    dp[i]=true;break;
                }
            }
        }
        return dp[0];
    }
};