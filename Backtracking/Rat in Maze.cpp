class Solution {
  public:
    int direX[4] = {1, 0, -1, 0};
    int direY[4] = {0, 1, 0, -1};
    string dire = "DRUL";
    void helper(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &vis, vector<string> &str, string s){
        if(i == n-1 && j == n-1)
        {
            str.push_back(s);
            s.pop_back();
            return;
        }
        
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int r = i + direX[k];
            int c = j + direY[k];
            char d = dire[k];
            if(r >= 0 && r < n && c >= 0 && c < n && mat[r][c] == 1 && !vis[r][c]){
                s += d;
                helper(r, c, n, mat, vis, str, s);
                s.pop_back();
            }
        }
        vis[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        if(mat[0][0] != 1) return {"-1"};
        vector<string> str;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        helper(0,0,n,mat,vis,str, "");
        return str;
    }
};