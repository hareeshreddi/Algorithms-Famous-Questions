class Solution {
public:
    int cur=0;
    bool dfs(int i,vector<vector<int>>&g,vector<int>&vis,vector<int>&ans){
        if(vis[i]) return vis[i]==2;
        vis[i]=1;
        for(int j=0;j<g[i].size();j++)
            if(!dfs(g[i][j],g,vis,ans)) return false;
        vis[i]=2;
        ans[cur++]=i;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>ans(numCourses,0);
        vector<int>temp;
        vector<vector<int>>g(numCourses,vector<int>());
        for(auto v:prerequisites) g[v[0]].push_back(v[1]);
        for(int i=0;i<numCourses;i++)
            if(!dfs(i,g,vis,ans)) return temp;
        return ans;
    }
};