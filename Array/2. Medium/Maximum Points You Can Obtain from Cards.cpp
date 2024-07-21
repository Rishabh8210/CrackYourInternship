class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int j = 0, i = 0;
        int n = cardPoints.size();
        int sum = 0;
        for(auto it: cardPoints){
            sum += it;
        }
        cout << sum << " ";
        int maxScore = 0;
        int winSum = 0;
        while(j < n){
            winSum += cardPoints[j];
            if((j - i + 1) < (n-k)){
                j++;
            }
            else if((j - i + 1) == (n-k)){
                maxScore = max(maxScore, sum - winSum);
                j++;
            }
            else if((j - i + 1) > (n-k)){
                while((j - i + 1) > (n-k)){
                    winSum -= cardPoints[i++];
                    maxScore = max(maxScore, sum - winSum);
                }
                j++;
            }
        }
        return maxScore;
    }
};