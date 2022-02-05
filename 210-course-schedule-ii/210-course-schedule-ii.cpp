class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>ans(numCourses,0);
        int s=0;
        vector<int>temp;
        vector<vector<int>>g(numCourses,vector<int>());
        for(const auto &v:prerequisites){
            g[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            const int r=q.front();q.pop();
            ans[s++]=r;
            for(int j=0;j<g[r].size();j++){
                if(--indegree[g[r][j]]==0) q.push(g[r][j]);
            }
        }
        return s==numCourses?ans:vector<int>();
    }
};