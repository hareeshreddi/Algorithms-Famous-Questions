class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans=0;
        int up_limit=(int)(sqrt(2*n+0.25)-0.5);
        for(int k=1;k<=up_limit;++k){
            n-=k;
            if(n%k==0) ans++;
        }
        return ans;
    }
};