class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0; int j = n-1;
        int maxContain = 0;
        while(i < j){
            int size = j - i;
            maxContain = max(maxContain, size*min(height[i], height[j]));
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxContain;
    }
};
