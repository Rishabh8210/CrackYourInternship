class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int n = haystack.size();
        dequeue
        while(j < n){
            if(((j-i) + 1) < needle.size()){
                winStr += haystack[j];
                j++;
            }
            else if(((j-i)+1) == needle.size()){
                if(winStr == needle)
                    return i;
                j++;
            }
            else if(((j-i)+1) > needle.size()){
                while((j-i)+1) > needle.size()){
                    reverse
                }
            }
        }
    }
};