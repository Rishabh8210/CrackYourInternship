class Solution {
public:
    int minCnt = 0;
    bool helper(int ind, int n, vector<int> &nums, vector<int> &dp, int &cnt){
        if(ind == n-1) return true;
        if(nums[ind] == 0) return false;
        // cout << ind << " "<< endl;
        if(dp[ind] != -1) return dp[ind];
        int reach = ind + nums[ind];
        for(int i = ind+1; i <= reach; i++){
            if(i < n && helper(i, n, nums, dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int cnt = 0;
        bool ans = helper(0, n, nums, dp, cnt);
        return ans;
    }
};