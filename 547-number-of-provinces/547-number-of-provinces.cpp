// class UnionFind {
// private:
//     vector<int>rank;
//     vector<int>parent;
//     int count;
// public:
//     UnionFind(int n){
//         this->count=n;
//         rank.resize(n,0);
//         parent.resize(n);
//         for(int i=0;i<n;i++)
//             parent[i]=i;
//     }
//     int find(int i){
//         if(i!=parent[i]) parent[i]=find(parent[i]);
//         return parent[i];
//     }
//     int getCount(){
//         return count;
//     }
//     void Union(int x,int y){
//         int root_x=find(x);
//         int root_y=find(y);
//         if(root_x!=root_y){
//             if(rank[root_x]>=rank[root_y]){
//                 rank[root_x]+=rank[root_y];
//                 parent[root_y]=root_x;
//             }
//             else{
//                 rank[root_y]+=rank[root_x];
//                 parent[root_x]=root_y;
//             }
//             --count;
//         }
//     }
// };
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // UnionFind uf(isConnected.size());
        // for(int i=0;i<isConnected.size();i++)
        //     for(int j=i+1;j<isConnected.size();j++)
        //         if(isConnected[i][j]==1) uf.Union(i,j);
        // return uf.getCount();
        vector<bool>visited(isConnected.size(),false);
        queue<int>q;
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]) continue;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int r=q.front();q.pop();
                for(int j=0;j<isConnected.size();j++)
                    if(isConnected[r][j]==1 && !visited[j]){
                        visited[j]=true;
                        q.push(j);
                    }
            }
            ++ans;
        }
        return ans;
    }
};