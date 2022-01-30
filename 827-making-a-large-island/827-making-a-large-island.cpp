class UnionFind {
private:
    vector<int>parent;
    vector<int>rank;
public:
  UnionFind(int n) {
      parent.resize(n,-1);
      rank.resize(n,0);
  }
  bool isValid(int i){
      return parent[i]>=0;
  }
  void setParent(int i){
      if(parent[i]==-1){
          parent[i]=i;
          rank[i]=1;
      }
  }
  int getParent(int i){
      return parent[i];
  }
  int getRank(int i){
      return rank[i];
  }
  void Union(int x,int y){
      int root_x=find(x);
      int root_y=find(y);
      if(root_x!=root_y){
          if(rank[root_x]>rank[root_y]){
              rank[root_x]+=rank[root_y];
              parent[root_y]=root_x;
          } else{
              rank[root_y]+=rank[root_x];
              parent[root_x]=root_y;
          }
      }
  }
  int find(int x){
      if(parent[x]!=x) return parent[x]=find(parent[x]);
      return parent[x];
  }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans=0,r=grid.size(),c=grid[0].size();
        bool f=true;
        UnionFind *uf = new UnionFind(r*c);
        for(int i=0;i<r;i++){
            int p=i*r-1;
            for(int j=0;j<c;j++){
                ++p;
                if(grid[i][j]==0) continue;
                uf->setParent(p);
                if(i+1<r && grid[i+1][j]==1){
                    uf->setParent(p+c);
                    uf->Union(p,p+c);
                }
                if(j+1<c && grid[i][j+1]==1){
                    uf->setParent(p+1);
                    uf->Union(p,p+1);
                }
            }
        }
        for(int i=0;i<r;i++){
            int p=i*r-1;
            for(int j=0;j<c;j++){
                ++p;
                if(grid[i][j]==1) continue;
                f=false;
                unordered_set<int>s;
                int cur=1;
                if(i+1<r && grid[i+1][j]==1) s.insert(uf->find(p+c));
                if(i-1>=0 && grid[i-1][j]==1) s.insert(uf->find(p-c));
                if(j+1<c && grid[i][j+1]==1) s.insert(uf->find(p+1));
                if(j-1>=0 && grid[i][j-1]==1) s.insert(uf->find(p-1));
                for(const auto &u:s)
                    cur+=uf->getRank(u);
                ans=max(ans,cur);
            }
        }
        if(f) return r*c;
        return ans;
    }
};