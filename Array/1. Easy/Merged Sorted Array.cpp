class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergedArray;
        int l1 = nums1.size();
        int l2 = nums2.size();
        sort(nums1.begin(), nums1.end()-n);
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < l1-n && j < l2){
            if(nums1[i] < nums2[j]){
                mergedArray.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] >= nums2[j]){
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }

        while(i < l1-n){
            mergedArray.push_back(nums1[i]);
            i++;
        }

        while(j < l2){
            mergedArray.push_back(nums2[j]);
            j++;
        }
        nums1 = mergedArray;
    }
};