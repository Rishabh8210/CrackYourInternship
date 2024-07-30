class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it: s){
            if(it == '(' || it == '{' || it == '[') st.push(it);
            else if(it == ')'){
                if(st.size()){
                    char peek = st.top();
                    if(peek == '('){
                        st.pop();
                    } else {
                        return false;
                    }
                } else{
                    return false;
                }
            }
            else if(it == ']'){
                if(st.size()){
                    char peek = st.top();
                    if(peek == '['){
                        st.pop();
                    } else {
                        return false;
                    }
                } else{
                    return false;
                }
            }
            else if(it == '}'){
                if(st.size()){
                    char peek = st.top();
                    if(peek == '{'){
                        st.pop();
                    } else {
                        return false;
                    }
                } else{
                    return false;
                }
            }
        }

        if(st.size() != 0) return false;
        return true;
    }
};