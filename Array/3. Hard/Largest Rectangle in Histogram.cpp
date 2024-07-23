class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        vector<int> leftSmall, rightSmall;
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            cout << endl;
            if(st.empty()){
                leftSmall.push_back(0);
                st.push(i);

            } else{
                leftSmall.push_back(st.top()+1);
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();
         for (int i = heights.size()-1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()){
                rightSmall.push_back(heights.size()-1);
                st.push(i);

            } else{
                rightSmall.push_back(st.top()-1);
                st.push(i);
            }
        }
        reverse(rightSmall.begin(), rightSmall.end());
        for (int i = 0; i < leftSmall.size(); i++) {
            int calLen = (((rightSmall[i] - leftSmall[i]) + 1) * heights[i]);
            largest = max(largest, calLen);
        }
        return largest;
    }
};