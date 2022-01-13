class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0,a=0,b=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]) b++;
            else{
                ans+=min(a,b);
                a=b;
                b=1;
            }
        }
        return ans+min(a,b);
    }
};