class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // best buying up to this point
        vector<int> minBuy(prices.size(), 0); 
        vector<int> maxSell(prices.size(), 0); 
        if(prices.size() <= 1){
            return 0; 
        }
        minBuy[0] = prices[0]; 
        for(int i = 1; i < prices.size(); i++){
            minBuy[i] = min(minBuy[i-1], prices[i]);
        }
        
        maxSell[prices.size() - 1] = prices[prices.size() - 1];
        for(int i = prices.size() - 2; i >= 0; i--){
            maxSell[i] = max(maxSell[i+1], prices[i]);
        }
        
        int result = 0; 
        
        for(int i = 0; i < prices.size() - 1; i++){
            int profit = maxSell[i+1] - minBuy[i];
            if(profit <= 0)
                continue;
            
            result = max(result, profit); 
            
        }
        
        return result; 
    }
};