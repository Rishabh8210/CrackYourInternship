class Solution {
public:
    bool checkByNeglecting(string s, int n){
        bool flag = false;
        int i = 0, j = n - 1;
        while(i < j){
            if(s[i] != s[j]){
                if(!flag){
                    i++;
                    flag = !flag;
                }
                else 
                    return false;
            } else{
                i++;j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        if(n <= 2) return true;
        string revS = s;
        reverse(revS.begin(), revS.end());

        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == revS[i]){
                cnt++;
            }
        }
        cout << cnt << " ";
        if(cnt == n || (n - cnt) == 1)
            return true;

        bool leftItrS = checkByNeglecting(s, n);
        bool rightItrS = checkByNeglecting(revS, n);

        cout << leftItrS << " " << rightItrS;
        if(leftItrS || rightItrS) return true;
        return false;
    }
};