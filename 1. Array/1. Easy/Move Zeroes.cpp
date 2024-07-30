class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind = 0;
        int cntZero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                cntZero++;
            }
            else{
                nums[ind++] = nums[i];
            }
        }
        int len = nums.size() - 1;
        while(cntZero--){
            nums[len--] = 0;
        }
    }
};