class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int n){
        count=0;
        parent.resize(n,-1);
        rank.resize(n,1);
    }
    bool isValid(int i){
        return parent[i]>=0;
    }
    void setParent(int i){
        if(parent[i]==-1){
            parent[i]=i;
            ++count;
        }
    }
    int getParent(int i){
        return parent[i];
    }
    int getCount(){
        return count;
    }
    int find(int i){ //Path Compression
        if(i!=parent[i]) parent[i]=find(parent[i]);
        return parent[i];
    }
    void Union(int x,int y){ //Union by Rank
        int root_x=find(x);
        int root_y=find(y);
        if(root_x!=root_y){
            if(rank[root_x]>=rank[root_y]){
                rank[root_x]+=rank[root_y];
                parent[root_y]=root_x;
            } else{
                rank[root_y]+=rank[root_x];
                parent[root_x]=root_y;
            }
            --count;
        }
    }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int>ans;
        UnionFind uf(m*n);
        for(const vector<int>pos:positions){
            int r=pos[0],c=pos[1],ind=r*n+c;
            vector<int>overlap;
            if(r-1>=0 && uf.isValid(ind-n)) overlap.push_back(ind-n);
            if(r+1<m  && uf.isValid(ind+n)) overlap.push_back(ind+n);
            if(c-1>=0 && uf.isValid(ind-1)) overlap.push_back(ind-1);
            if(c+1<n  && uf.isValid(ind+1)) overlap.push_back(ind+1);
            uf.setParent(ind);
            for(const int p:overlap) uf.Union(ind,p);
            ans.push_back(uf.getCount());
        }
        return ans;
    }
};


//other similar kind of implementation for find method
// while(i!=parent[i]){
//     parent[i]=parent[parent[i]];
//     i=parent[i];
// }
// return i;

//other way of initialization
// UnionFind *uf=new UnionFind(m*n);