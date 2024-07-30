class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            int j = i+1, k = n-1;
            vector<int> result(3, -1);
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    result[0] = nums[i];
                    result[1] = nums[j];
                    result[2] = nums[k];
                    st.insert(result);
                    j++;k--;
                }
                else if(sum > 0){
                    k--;
                }
                else
                    j++;
            }
        }
        vector<vector<int>> answer(st.begin(), st.end());
        return answer;
    }
};