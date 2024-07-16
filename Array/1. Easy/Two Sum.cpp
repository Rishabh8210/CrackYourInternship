class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++){
            int remSum = target - nums[i];
            if(mp.find(remSum) != mp.end()){
                return {mp[remSum], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};