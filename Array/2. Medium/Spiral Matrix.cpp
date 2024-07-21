class Solution {
public:
    void print(vector<int> &res){
        cout << endl;
        for(auto it : res){
            cout << it << " ";
        }
        cout << endl;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        int leftR = 0, rightR = n-1;
        int leftC = 0, rightC = m-1; 
        while(leftR <= rightR && leftC <= rightC){
            for(int i = leftC; i <= rightC; i++){
                res.push_back(matrix[leftR][i]);
            }
            leftR++;
            print(res);
            for(int i = leftR; i <= rightR; i++){
                res.push_back(matrix[i][rightC]);
            }
            rightC--;
            print(res);
            if(leftR <= rightR){
                for(int i = rightC; i >= leftC; i--){
                    res.push_back(matrix[rightR][i]);
                }
                rightR--;
                print(res);
            }
            if(leftC <= rightC){
                for(int i = rightR; i >= leftR; i--){
                    res.push_back(matrix[i][leftC]);
                }
                leftC++;
                print(res);
            }
        }
        return res;
    }
};