class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minP = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minP){
                minP = prices[i];
            }
            else{
                maxProfit = max(maxProfit, prices[i] - minP);
            }
        }
        return maxProfit;
    }
};