class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool>vis(s.length(),false);
        vis[0]=true;
        queue<int>q;
        q.push(0);
        vis[0]=true;
        int max1=0;//covered until (for special case all 0;1 and max length)
        while(!q.empty() && !vis[s.length()-1]){
            int r=q.front();
            int m1=max(r+minJump,max1+1),m2=min(r+maxJump,(int)s.length()-1);
            q.pop();
            for(int p=m1;p<=m2;++p){
                if(s[p]=='0'&&!vis[p]){
                    vis[p]=true;
                    q.push(p);
                }
            }
            max1=max(max1,r+maxJump);
        }
        return vis[s.length()-1];
    }
};