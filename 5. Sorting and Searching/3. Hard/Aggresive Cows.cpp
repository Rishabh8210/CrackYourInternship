// User function Template for C++

class Solution {
public:

    bool checkPossibility(vector<int> &stalls, int k, int spaces)
{
    int minCow = 1;
    int last = stalls[0];
    for(int i = 1; i < stalls.size(); i++)
    {
        if(stalls[i] - last >= spaces)
        {
            minCow++;
            last = stalls[i];
        }
        if(minCow >= k)
        {
            return true;
        }
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int maxStallSpaces = -1;
    int maxSpaces = *max_element(stalls.begin(), stalls.end());
    int low = 1;int high = maxSpaces;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(checkPossibility(stalls, k, mid) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
};