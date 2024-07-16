class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        int i = 0, j = 0;
        long long minDiff = 1e9;
        while(j < n){
            if(((j - i) + 1) < m){
                j++;
            }
            else if(((j-i)+1) == m){
                minDiff = min(minDiff, (a[j] - a[i]));
                j++;i++;
            }
        }
        return minDiff;
    }   
};