class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0,a=0,b;
        if(s[0]=='1') ++ones;
        for(int i=1;i<s.length();i++){
            if(s[i]=='1') b=a,++ones;
            else b=min(ones,a+1);
            a=b;
        }
        return a;
    }
};