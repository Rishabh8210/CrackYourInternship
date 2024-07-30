class Solution {
public:
    int direX[4] = {1, 0, -1, 0}; 
    int direY[4] = {0, 1, 0, -1}; 
    bool dfs(int ind, int row, int col, int n, int m, vector<vector<char>>& board, string word, vector<vector<int>>& vis){
        if(!(row >= 0 && col >= 0 && row < n && col < m) || board[row][col] != word[ind]) return false;
        if(ind == word.size()-1) return true;
        vis[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int newR = row + direX[i];
            int newC = col + direY[i];
            if(newR >= 0 && newC >= 0 && newR < n && newC < m && !vis[newR][newC] ){
                if(dfs(ind+1, newR, newC, n, m, board, word, vis)) return true;
            }
        }
        vis[row][col] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        char start = word[0];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == start){
                    if(dfs(0, i, j, n, m, board, word, vis) == true)
                        return true;
                }
            }
        }
        return false;
    }
};