class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int cur,vector<int>&color){
        if(color[cur]) return color[cur]==2;
        color[cur]=1;
        for(vector<int>::iterator it=graph[cur].begin();it!=graph[cur].end();++it){
            if(!dfs(graph,*it,color)) return false;
        }
        color[cur]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int k=graph.size();
        vector<int>ans;
        vector<int>color(k,0);
        for(int i=0;i<k;i++)
            if(dfs(graph,i,color)) ans.push_back(i);
        return ans;
    }
};