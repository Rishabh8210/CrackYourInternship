class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());

        int i=0,j=1;
        while(j<n){
            int diff=arr[j]-arr[i];
            if(diff==x) return 1;
            else if(diff<x) j++;
            else{
                i++;
                if(i==j) j++;
            }
        }
        return -1;
    }
};