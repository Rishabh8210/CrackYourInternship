class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int k = j+1, l = n-1;
                while(k < l){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> ans({nums[i], nums[j], nums[k], nums[l]});
                        st.insert(ans);
                        k++;l--;
                    }
                    else if(sum > target){
                        l--;
                    }else{
                        k++;
                    }
                }
            }
        }

        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};