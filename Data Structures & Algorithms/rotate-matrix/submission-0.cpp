class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    // using upper triangular matrix to get the transpose of the matrix
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    } 
    // we can also use lower triangular matrix for transpose of a matrix
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         swap(matrix[i][j],matrix[j][i]);
    //     }
    // }
    // now we just need to reverse all the rows to get the rotated matrix    
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    }
};
