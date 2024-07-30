class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};