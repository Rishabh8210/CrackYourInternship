class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        result.push_back(arr);
        while(next_permutation(arr.begin(), arr.end())){
            result.push_back(arr);
        }
        return result;
    }
};