class Solution {
public:
    bool undirectedcycle(int i,int parent,vector<vector<int>>&adj,vector<int>&visited,int & count){
        visited[i]=1;
        count++;
        for(auto it:adj[i]){
            if(visited[it]==0){
                if(undirectedcycle(it,i,adj,visited,count)) return true;
            }
            else if(it!=parent) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,0);
        int count=0;
        bool valid=undirectedcycle(0,-1,adj,visited,count);
        if(count!=n) return false;
        if(valid) return false;
        return true;
    }
};
