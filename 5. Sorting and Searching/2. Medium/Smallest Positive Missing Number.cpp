
class Solution
{
    
    public:
    int shift(int arr[], int n){
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] <= 0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return j;
    }
    
    int findMissingNumber(int arr[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            if(abs(arr[i])-1 < n && arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i])-1] = - arr[abs(arr[i]) - 1];
        }
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(arr[i] > 0) 
            return i+1;
        }
        return n+1;
    }
    
    int missingNumber(int arr[], int n) 
    {
        int afrShiftedInd = shift(arr, n);
        
        int missingNo = findMissingNumber(arr+afrShiftedInd, n - afrShiftedInd);
        return missingNo;
    } 
};