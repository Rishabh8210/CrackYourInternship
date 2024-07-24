class Solution {
public:
    void helper(int open, int close, int n, string str, vector<string> &res){
        if(open == n){
            res.push_back(str);
            cout << str << " ";
            return;
        }
        if(close == n) return;

        if(open == 0){
            str += "(";
            helper(open+1, close, n, str, res);
        } else{
            str += "(";
            helper(open+1, close, n, str, res);
            str.pop_back();
            str += ")";
            helper(open, close+1, n, str, res);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(0, 0, n, "", res);
        for(int i = 0; i < res.size(); i++){
            int size = res[i].size();
            string addClosing = res[i];
            int remSize = (2*n) - size;
            while(remSize--){
                addClosing += ")";
            }
            res[i] = addClosing;
        }
        vector<string> ans;
        for(auto it: res){
            int open = 0, close = 0;
            bool flag = true;
            for(auto i : it){
                if(i == '(') open++;
                else close++;
                if(close > open){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(it);
        }
        return ans;
    }
};