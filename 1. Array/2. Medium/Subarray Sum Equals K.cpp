class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k) cnt++;
            int leftK = sum - k;
            if(mp.find(leftK) != mp.end()){
                cnt += mp[leftK];
            }
            mp[sum]++;
        }
        return cnt;
    }
};