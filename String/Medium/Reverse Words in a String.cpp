class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                if(temp.size() == 0)
                    continue;
                else{
                    st.push(temp);
                    temp = "";
                    cnt++;
                }
            }
            else
            {
                temp += s[i];
            }
        }
        if(temp.size() != 0){
            st.push(temp);
            cnt++;
        }
        string ans = "";
        while(!st.empty())
        {
            if(cnt == 1)
            {
                ans += st.top();
            }
            else
            {
                ans += st.top();
                ans += ' ';
                cnt--;
            }
            st.pop();
        }
        return ans;
    }
};