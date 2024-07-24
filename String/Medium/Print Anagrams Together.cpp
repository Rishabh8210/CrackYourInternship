class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<string, vector<string>> mp;
        vector<int> vis(26, 0);
        for(auto it : string_list){
            string temp = it;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(it);
        }
        
        vector<vector<string>> res;
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};