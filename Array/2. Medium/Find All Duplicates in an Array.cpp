class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                int temp = nums[i] * -1;
                if(nums[temp-1] < 0)
                    result.push_back(temp);
                else
                    nums[temp-1] *= -1;
            }else{
                int temp = nums[i];
                if(nums[temp-1] < 0)
                    result.push_back(temp);
                else
                    nums[temp-1] *= -1; 
            }
        }

        return result;
    }
};