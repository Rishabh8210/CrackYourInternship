class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int direX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int direY[8] = {1, 1, 0, -1, -1, -1, 0, 1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int live = 0 ,dead = 0;
                for(int k = 0; k < 8; k++){
                    int newR = i + direX[k];
                    int newC = j + direY[k];
                    if(newR >= 0 && newC >= 0 && newC < m && newR < n){
                        if(board[newR][newC] == 1) live++;
                        else dead++;
                    }
                }
                cout << live << " " << dead << " " << i << " " << j << endl;
                if(board[i][j]){
                    if(live == 2 || live == 3)
                        vis[i][j] = 1;
                }else{
                    if(live == 3)
                        vis[i][j] = 1;
                }
            }
        }
        board = vis;
    }
};