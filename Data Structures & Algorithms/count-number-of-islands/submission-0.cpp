class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& grid,int r,int c,vector<vector<bool>>&visited){
        visited[r][c]=true;
        for(auto & it:dir){
            int nr=r+it.first;
            int nc=c+it.second;
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1'){
                if(!visited[nr][nc]){
                    dfs(grid,nr,nc,visited);
                }
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                dfs(grid,i,j,visited);
                count++;
            }
        }
    } 
    return count;  
    }
};
