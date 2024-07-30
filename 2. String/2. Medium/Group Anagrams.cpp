class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0)
            return {{""}};
        unordered_map<string, vector<string>> mp1;

        for (auto s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp1[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it : mp1) {
            ans.push_back(it.second);
        }
        return ans;
    }
};