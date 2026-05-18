class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>indegree(numCourses,0);
    vector<vector<int>>adj(numCourses);
    for(int i=0;i<prerequisites.size();i++){
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b].push_back(a);
        indegree[a]++;
    }  
    queue<int>q;  
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>toposort;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        toposort.push_back(node);
        for(auto & child:adj[node]){
            indegree[child]--;
            if(indegree[child]==0){
                q.push(child);
            }
        }
    }
    if(toposort.size()==numCourses) return toposort;
    else return {};   
    }
};
