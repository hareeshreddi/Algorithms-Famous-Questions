class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.length()-1]=='1') return false;
        queue<int>q;
        q.push(0);
        int max1=0;//tells covered until (for special case all 0;1 and max length)
        while(!q.empty()){
            int r=q.front();
            int m1=max(r+minJump,max1+1),m2=min(r+maxJump,(int)s.length()-1);
            if(m1<=m2 && m2==s.length()-1) return true;
            q.pop();
            for(int p=m1;p<=m2;++p)
                if(s[p]=='0') q.push(p);
            max1=m2;
        }
        return false;
    }
};
// "00111010"
// 3
// 5