class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int>> vp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    vp.push_back({i, j});
                }
            }
        }

        for(auto it : vp){
            int row = it.first;
            int col = it.second;
            cout << row << col << endl;
            for(int i = 0; i < m; i++){
                matrix[row][i] = 0;
            }
            for(int i = 0; i < n; i++){
                matrix[i][col] = 0;
            }
        }
    }
};