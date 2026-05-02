class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    int n=board.size();
    int m=board[0].size();
    for(int i=0;i<9;i++){
        unordered_set<int>r;
        for(int j=0;j<9;j++){
            if(board[i][j]=='.') continue;
            if(r.find(board[i][j])!=r.end()) return false;
            r.insert(board[i][j]);
        }
    }   
    for(int i=0;i<9;i++){
        unordered_set<int>c;
        for(int j=0;j<9;j++){
            if(board[j][i]=='.') continue;
            if(c.find(board[j][i])!=c.end()) return false;
            c.insert(board[j][i]);
        }    
    }
    for(int s=0;s<9;s++){
        unordered_set<int>sq;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int r=(s/3)*3+i;
                int c=(s%3)*3+j;
                if(board[r][c]=='.') continue;
                if(sq.find(board[r][c])!=sq.end()) return false;
                sq.insert(board[r][c]);
            }
        }
    }
    return true;
    }
};
