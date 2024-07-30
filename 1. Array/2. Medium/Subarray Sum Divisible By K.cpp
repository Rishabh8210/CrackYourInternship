class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int cnt = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = (sum % k);
            if(rem < 0) rem += k;
            if(ump.find(rem) != ump.end()){
                cnt += ump[rem];
                ump[rem]++;
            }else{
                ump[rem] = 1;
            }
        }
        return cnt;
    }
};