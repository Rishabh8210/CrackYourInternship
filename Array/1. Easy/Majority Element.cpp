class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = INT_MIN;
        int maxCntElem = 0;
        for(auto it : nums)
        {
            if(maxCntElem == 0)
            {
                elem = it;
                maxCntElem++;
            }
            else 
            {
                if(elem == it)
                    maxCntElem++;
                else
                    maxCntElem--;
            }
        }
        int cnt = 0;
        for(auto it : nums)
        {
            if(it == elem)
                cnt++;
        }
        if(cnt >= nums.size() / 2)
            return elem;
        return -1;
    }
};