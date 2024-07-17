class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int iniBuy = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(iniBuy > prices[i]){
                iniBuy = prices[i];
            }else{
                maxProfit += (prices[i] - iniBuy);
                iniBuy = prices[i];
            }
        }
        return maxProfit;
    }
};