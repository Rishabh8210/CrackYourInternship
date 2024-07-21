class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        sort(arr.begin(), arr.end());
        string ans = "";
        string chota = arr[0];
        string bada = arr[arr.size()-1];

        for(int i = 0; i < chota.size(); i++)
        {
            if(chota[i] == bada[i])
                ans += chota[i];
            else
                break;
        }
        return ans;
    }
};