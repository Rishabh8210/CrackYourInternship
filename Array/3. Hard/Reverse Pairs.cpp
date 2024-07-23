class Solution {
public:
    void merge(int left, int mid, int right, vector<int> &nums){
        vector<int> tempArr;
        int i = left, j = mid+1;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                tempArr.push_back(nums[i++]);
            }else{
                tempArr.push_back(nums[j++]);
            }
        }

        while(i <= mid){
            tempArr.push_back(nums[i++]);
        }

        while(j <= right){
            tempArr.push_back(nums[j++]);
        }

        for(int i = left; i <= right; i++){
            nums[i] = tempArr[i-left];
        }
    }
    int countPairs(int left, int mid, int right, vector<int> &nums){
        int cnt = 0;
        int i = left, j = mid+1;
        while(i <= mid){
            while(j <= right){
                long long sndTimeX = 2 * 1LL * nums[j];
                if(sndTimeX < nums[i]){
                    j++;
                } else {
                    break;
                }
            }
            cnt += (j - (mid+1));
            i++;
        }
        return cnt;
    }
    int mergeSort(int left, int right, vector<int> &nums){
        int cnt = 0;
        if(left >= right)
            return cnt;
        
        int mid = left + ((right - left) / 2);
        cnt += mergeSort(left, mid, nums);
        cnt += mergeSort(mid+1, right, nums);
        cnt += countPairs(left, mid, right, nums);
        merge(left, mid, right, nums);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int res = mergeSort(0, nums.size()-1, nums);
        return res;
    }
};