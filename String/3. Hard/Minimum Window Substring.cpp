class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto it : t){   
            mp[it]++;
        }
        int j = 0;
        int i = 0;
        int size = mp.size();
        int maxPossi = s.size();
        int start = -1;
        int end = -1;
        while(j < s.size())
        {
            if(mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    size--;
                }
            }
            if(size == 0){
                while(size == 0)
                {
                    if(mp.find(s[i]) != mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            size++;
                            if(maxPossi >= j-i+1)
                            {
                                maxPossi = j-i+1;
                                start = i;
                                end = j;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        cout << start << " " << end;
        if(start == -1 || end == -1) return "";
        string ans = "";
        while(start <= end)
        {
            ans += s[start++];
        }
        return ans;
    }
};