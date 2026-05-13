class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
    int fresh=0;
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1) fresh++;
        }
    }   
    if(fresh==0) return 0;
    if(q.empty()) return -1;
    int time=0;
    while(!q.empty()){
        int size=q.size();
        bool rotted=false;
        for(int i=0;i<size;i++){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(auto & it:dir){
                int nr=r+it.first;
                int nc=c+it.second;
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    fresh--;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    rotted=true;
                }
            }
        }
        if(rotted)time++;
    }
    return (fresh!=0)?-1:time;
    }
};
