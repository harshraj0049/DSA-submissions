class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&visited){
        visited[i]=1;
        for(auto it:adj[i]){
            if(visited[it]==0){
                dfs(it,adj,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};
