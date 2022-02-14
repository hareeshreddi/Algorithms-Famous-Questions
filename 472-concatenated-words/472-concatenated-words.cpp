class Solution {
private:
    vector<bool>dp;
public:
    bool wordBreak(string &s, unordered_set<string>&us) {
        for(int i=1;i<=s.length();i++) dp[i]=false;
        for(int i=1;i<=s.length();i++)
            for(int j=i;j>0;j--){
                if(i-j+1>30) break;//length of each word<=30
                if(dp[j-1] && us.find(s.substr(j-1,i-j+1))!=us.end()){
                    dp[i]=true;break;
                }
            }
        return dp[s.length()];
    }
    static bool func(const string &s1,const string &s2){
        return s1.size()<s2.size();
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.size()<=2) return {};
        dp.resize(words.size(),false);
        dp[0]=true;
        sort(words.begin(),words.end(),func);
        vector<string>ans;
        unordered_set<string>us;
        us.insert(words[0]);us.insert(words[1]);
        for(int i=2;i<words.size();i++){
            if(wordBreak(words[i],us)) ans.push_back(words[i]);
            us.insert(words[i]);
        }
        return ans;
    }
};