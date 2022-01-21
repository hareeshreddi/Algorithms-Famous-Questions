class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int ans=0,n=board.size(),r=n*n;
        vector<bool>vis(n*n+1,false);
        vis[1]=true;
        queue<pair<int,int>>q;//val,ans
        q.push({1,0});
        while(!q.empty()){
            pair<int,int>p=q.front();q.pop();
            int ind=p.first,cur=p.second+1,ind1;
            for(int i=1;i<=6&&i+ind<=r;i++){
                int val=extract(board,i+ind);
                if(val!=-1) ind1=val;
                else ind1=ind+i;
                if(ind1==r) return cur;
                if(!vis[ind1]){
                    q.push({ind1,cur});
                    vis[ind1]=true;
                }
            }
        }
        return -1;
    }
    int extract(vector<vector<int>>& board, int num) {
        int n=board.size();
        int r=(num - 1) / n;
        int x=n - 1 - r;
        int y=(r % 2 == 0) ? num-1-r*n :(1+r)*n-num;
        return board[x][y];
    }
};