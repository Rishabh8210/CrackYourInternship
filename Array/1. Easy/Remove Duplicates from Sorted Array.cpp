class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 1;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != prev){
                prev = nums[i];
                nums[ind++] = nums[i];
            }
        }
        return ind;
    }
};